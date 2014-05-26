#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

/* Time in seconds from some point in the past */
double dwalltime();

int n_proc,N,chunk;
double *values;

void first_work(int myid){
    MPI_Status status;
    double *buffer;
    // = (double*)malloc(sizeof(double)*chunk*N);
    MPI_Recv(buffer, chunk*N, MPI_DOUBLE, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
    min = buffer[1];
    max = buffer[1];
    for(i=0;i<chunk*N;i++){
       if (buffer[i]<min) min=buffer[i];
       if (buffer[i]<max) max=buffer[i];
       avg+=buffer[i];
    }

    values[0] = min;
    values[1] = max;
    values[2] = avg;

    MPI_Send(&values, 3, MPI_DOUBLE, 0,  MPI_ANY_TAG, MPI_COMM_WORLD);
    
}


int main(int argc,char*argv[]){
 double *A,*B;
 double min,max,avg=0; 
 int i;
 int check=1;
 double timetick;

 //Controla los argumentos al programa
  if (argc < 2){
   printf("\n Faltan argumentos:: N dimension de la matriz \n");
   return 0;
  }
   N=atoi(argv[1]);

 //Aloca memoria para las matrices
  A=(double*)malloc(sizeof(double)*N*N);
  B=(double*)malloc(sizeof(double)*N*N);
  // Array to communicate min, max and average
  values = (double*)malloc(sizeof(double)*3);
  //Inicializa la matriz 
  for(i=0;i<N*N;i++){
	A[i]= 1.0;
  }   
 
  int id;
 timetick = dwalltime();
 MPI_Init(&argc, &argv);
 MPI_Comm_size(MPI_COMM_WORLD, &n_proc);
 MPI_Comm_rank(MPI_COMM_WORLD, &id);
 chunk=N/n_proc;

 if (myid == 0){
     int worker_id;

     for(worker_id=1;worker_id<n_proc;worker_id++)
	 MPI_Send (&A[chunk*worker_id], chunk, MPI_DOUBLE, worker_id, MPI_ANY_TAG, MPI_COMM_WORLD);
  }
 //else{//MASTER is our master now
 //  worker(myid);
 // }

 
 min = A[1];
 max = A[1];
  for(i=0;i<N*N;i++){
       if (A[i]<min) min=A[i];
       if (A[i]<max) max=A[i];
       avg+=A[i];
  }

  avg/=N;

  for(i=0;i<N*N;i++){
       if (A[i]<avg) B[i]=min;
       if (A[i]>avg) B[i]=max;
       if (A[i]==avg) B[i]=avg;
  }


 MPI_Finalize();
    printf("Tiempo en segundos: %f \n", dwalltime() - timetick);

  //Chequea los resultados
  for(i=0;i<N*N;i++){
	check= check&&(B[i]==1.0);
  }   

  if(check){
   printf("Resultado correcto\n");
  }else{
   printf("Resultado erroneo\n");
  }
 free(A);
 free(B);
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
