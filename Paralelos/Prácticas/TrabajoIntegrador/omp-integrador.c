#include<stdio.h>
#include<stdlib.h>
#include<omp.h> 
#include<mpi.h>
#include<math.h>

#define MANAGER 0

/* Time in seconds from some point in the past */
double dwalltime();


int main(int argc,char*argv[]){
    double *A,*B,*C,*W,*results, *Buffer;
    int i,j,k,N,tid;
 int check=1;
 double temp,total;
 double timetick;

 //Controla los argumentos al programa
  if (argc < 3){
   printf("\n Faltan argumentos:: N dimension de la matriz y cantidad de threads \n"); 
   return 0;
  }
   N=atoi(argv[1]);
   int numThreads = atoi(argv[2]);
   omp_set_num_threads(numThreads);	


 int worker_id, n_proc, chunk, size_chunk;
 MPI_Init(&argc, &argv);
 MPI_Comm_size(MPI_COMM_WORLD, &n_proc);
 MPI_Comm_rank(MPI_COMM_WORLD, &worker_id);
 MPI_Status status;
 chunk=N/n_proc;
 size_chunk=chunk*N;

  B=(double*)malloc(sizeof(double)*N*N);
  Buffer=(double*)malloc(sizeof(double)*size_chunk);

 if(worker_id == MANAGER){
  //Aloca memoria para las matrices
       A=(double*)malloc(sizeof(double)*N*N);
       C=(double*)malloc(sizeof(double)*N*N);
       W=(double*)malloc(sizeof(double)*N*N);
       //Inicializa la matriz 
       for(i=0;i<N;i++){
  	for(j=0;j<N;j++){
  		A[i*N+j]= 1.0;
  		//Los valores para la matriz B deben ser cargados como una matriz transpuesta.
  		B[i+N*j]= 1.0;
 		C[i*N+j]= 0.0;
  		W[i*N+j]= 1.0;
      }
    }
 }
 else {
       A=(double*)malloc(sizeof(double)*size_chunk);
       W=(double*)malloc(sizeof(double)*size_chunk);
  }
 
  MPI_Scatter (A, size_chunk, MPI_DOUBLE, A, size_chunk, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  MPI_Scatter (W, size_chunk, MPI_DOUBLE, W, size_chunk, MPI_DOUBLE, 0, MPI_COMM_WORLD);


#pragma omp parallel default(none) private(i,j,total,temp,timetick,tid,chunk,B) shared(A,C,W,N)
{
  tid= omp_get_thread_num();
  timetick = dwalltime();

  //Calcula la media ponderada
  #pragma omp for private(i,j) schedule(static,1) nowait
  for(i=0;i<chunk;i++){
	for(j=0;j<N;j++){
	   temp += W[i*N+j];
	   total += A[i*N+j] * W[i*N+j];
	}
  }
}
  
   MPI_Allreduce(&temp, &temp, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
   MPI_Allreduce(&total, &total, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
 
   total/=temp;

#pragma omp parallel default(none) private(i,j,total,temp,timetick,tid,chunk,B) shared(A,C,W,N)
{
  tid= omp_get_thread_num();
  timetick = dwalltime();
  
  #pragma omp for private(i,j,k) schedule(static,1) nowait
  //Realiza la ecuacion general
  for(i=0;i<N;i++){
	for(j=0;j<N;j++){
		for(k=0;k<N;k++){
			C[i*N+j]+=sqrt((pow(A[i*N+k]-total,2))*(pow(B[j*N+k]-total,2)));
		}
	}
  }
 



    printf("Tiempo en segundos para el thread %d: %f \n", tid,dwalltime() - timetick);
}

MPI_Gather(Buffer, size_chunk, MPI_DOUBLE, C, size_chunk, MPI_DOUBLE, MANAGER, MPI_COMM_WORLD);

  if(worker_id == MANAGER){
  //Chequea los resultados
  for(i=0;i<N*N;i++)
	check= check&&(C[i]==0.0);
  if(check){
   printf("Resultado correcto\n");
  }else{
   printf("Resultado erroneo\n");
  }
 free(C);
 }
 free(A);
 free(B);
 free(Buffer);
 free(W);
 return(0);
}



/*****************************************************************/

#include <sys/time.h>

double dwalltime()
{
	double sec;
	struct timeval tv;

	gettimeofday(&tv,NULL);
	sec = tv.tv_sec + tv.tv_usec/1000000.0;
	return sec;
}
