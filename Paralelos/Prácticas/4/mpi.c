#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

#define MANAGER 0

/* Time in seconds from some point in the past */
double dwalltime();

int N,chunk;

int main(int argc,char*argv[]){
 double *A,*B;
 double min,max,avg,avg_sum; 
 int i;
 int check=1;
 double timetick;
 //Controla los argumentos al programa
  if (argc < 2){
   printf("\n Faltan argumentos:: N dimension de la matriz \n");
   return 0;
  }
  N=atoi(argv[1]);
 int worker_id, n_proc;
 MPI_Init(&argc, &argv);
 MPI_Comm_size(MPI_COMM_WORLD, &n_proc);
 MPI_Comm_rank(MPI_COMM_WORLD, &worker_id);
 MPI_Status status;
 chunk=(N*N)/n_proc;

 if(worker_id == MANAGER){
     A=(double*)malloc(sizeof(double)*N*N);
     B=(double*)malloc(sizeof(double)*N*N);
 }
 else{
     A=(double*)malloc(sizeof(double)*chunk);
     B=(double*)malloc(sizeof(double)*chunk);
 }

 MPI_Scatter (A, chunk, MPI_DOUBLE, A, chunk, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  for(i=0;i<chunk;i++){
	A[i]= 1.0;
  }   

 
 MPI_Gather(A, chunk, MPI_DOUBLE, A, chunk, MPI_DOUBLE, 0, MPI_COMM_WORLD);

 timetick = dwalltime();

 min=A[0];
 max=A[0];
 avg=0;
  for(i=0;i<chunk;i++){
    if (A[i]<max) max=A[i];
    if (min<A[i]) min=A[i];
    avg+=A[i];
  }   
 
  MPI_Allreduce(&avg, &avg_sum, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
  MPI_Allreduce(&min, &min, 1, MPI_DOUBLE, MPI_MIN, MPI_COMM_WORLD);
  MPI_Allreduce(&max, &max, 1, MPI_DOUBLE, MPI_MAX, MPI_COMM_WORLD);
 
  avg=avg_sum/(N*N);

 MPI_Scatter (A, chunk, MPI_DOUBLE, B, chunk, MPI_DOUBLE, 0, MPI_COMM_WORLD);

 for(i=0;i<chunk;i++){
    if (B[i]<avg) B[i]=min;
    if (B[i]>avg) B[i]=max;
    if (B[i]==avg) B[i]=avg;
  }


 MPI_Gather(B, chunk, MPI_DOUBLE, B, chunk, MPI_DOUBLE, 0, MPI_COMM_WORLD);

 printf("Tiempo en segundos: %f \n", dwalltime() - timetick);

  //Chequea los resultados
 MPI_Scatter (B, chunk, MPI_DOUBLE, B, chunk, MPI_DOUBLE, 0, MPI_COMM_WORLD);

 for(i=0;i<chunk;i++){
	check= check&&(B[i]==1.0);
  }

  MPI_Allreduce(&check, &check, 1, MPI_INT, MPI_LAND, MPI_COMM_WORLD);
   if(worker_id == MANAGER)
  if(check){
      printf("Resultado correcto\n");
  }else{
   printf("Resultado erroneo\n");
  }
 free(A);
 free(B);
 MPI_Finalize();
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
