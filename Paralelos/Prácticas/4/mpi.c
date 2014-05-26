#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

#define MANAGER 0

/* Time in seconds from some point in the past */
double dwalltime();

int j,n_proc,N,chunk;

void first_work(){
}


int main(int argc,char*argv[]){
 double *A,*B;
 double min,max,avg_sum; 
 int i;
 int check=1;
 double timetick;
 double *buffer, *values;

 //Controla los argumentos al programa
  if (argc < 2){
   printf("\n Faltan argumentos:: N dimension de la matriz \n");
   return 0;
  }
   N=atoi(argv[1]);

 //Aloca memoria para las matrices
  A=(double*)malloc(sizeof(double)*N*N);
  B=(double*)malloc(sizeof(double)*N*N);
  buffer=(double*)malloc(sizeof(double)*chunk*N);
  // Array to communicate min, max and average
  values=(double*)malloc(sizeof(double)*3*N);


  //Inicializa la matriz 
  for(i=0;i<N*N;i++){
	A[i]= 1.0;
  }   
 
  int id;
 timetick = dwalltime();

 MPI_Init(&argc, &argv);
 MPI_Comm_size(MPI_COMM_WORLD, &n_proc);
 MPI_Comm_rank(MPI_COMM_WORLD, &id);
 MPI_Status status;
 chunk=N/n_proc;

 MPI_Scatter (A, chunk*N, MPI_DOUBLE, buffer, chunk*N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

 MPI_AllReduce (&buffer, &avg_sum, chunk*N, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
 MPI_AllReduce (&buffer, &values[0], chunk*N, MPI_DOUBLE, MPI_MIN, 0, MPI_COMM_WORLD);
 MPI_AllReduce (&buffer, &values[1], chunk*N, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
 
 values[2]=avg_sum/N;


 MPI_Scatter (A, chunk*N, MPI_DOUBLE, buffer, chunk*N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

 for(i=0;i<chunk*N;i++){
    if (buffer[i]<avg) buffer[i]=min;
    if (buffer[i]>avg) buffer[i]=max;
    if (buffer[i]==avg) buffer[i]=avg;
  }


 MPI_Gather(buffer, chunk*N, MPI_DOUBLE, B, chunk*N, chunk*N, MPI_DOUBLE, 0, MPI_COMM_WORLD);



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
