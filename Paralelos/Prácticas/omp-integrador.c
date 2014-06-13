#include<stdio.h>
#include<stdlib.h>
#include<omp.h> 
#include<math.h>

/* Time in seconds from some point in the past */
double dwalltime();


int main(int argc,char*argv[]){
    double *A,*B,*C,*W;
 int i,j,k,N,tid;
 int check=1;
 double temp;
 double timetick;

 //Controla los argumentos al programa
  if (argc < 3){
   printf("\n Faltan argumentos:: N dimension de la matriz \n");
   return 0;
  }
   N=atoi(argv[1]);
   int numThreads = atoi(argv[2]);
   omp_set_num_threads(numThreads);	

 //Aloca memoria para las matrices
  A=(double*)malloc(sizeof(double)*N*N);
  B=(double*)malloc(sizeof(double)*N*N);
  C=(double*)malloc(sizeof(double)*N*N);
  W=(double*)malloc(sizeof(double)*N*N);

  //Inicializa la matriz 
  for(i=0;i<N;i++){
	for(j=0;j<N;j++){
		A[i*N+j]= 1.0;
		B[i*N+j]= 1.0;
		C[i*N+j]= 1.0;
		W[i*N+j]= 1.0;
    }
  }   
 
  #pragma omp parallel default(none) private(i,j,temp,timetick,tid)   shared(A,B,C,W,N)
{
  tid= omp_get_thread_num();
  timetick = dwalltime();

  double total = 0;
  //Calcula la media ponderada
  #pragma omp for private(i,j,temp,total) schedule(static,1) nowait
  for(i=0;i<N;i++){
	for(j=0;j<N;j++){
	   temp += W[i*N+j];
	   total += A[i*N+j] * W[i*N+j];
	}
  }

  total/=temp;

  #pragma omp for private(i,j,k,total) schedule(static,1) nowait
  //Realiza la ecuacion general
  for(i=0;i<N;i++){
	for(j=0;j<N;j++){
		for(k=0;k<N;k++){
			C[i*N+j]=sqrt((pow(A[i*N+j]-total,2))*(pow(B[i*N+j]-total,2)));
		}
	}
  }

    printf("Tiempo en segundos para el thread %d: %f \n", tid,dwalltime() - timetick);
}
  //Chequea los resultados
  for(i=0;i<N;i++){
	check= check&&(C[i]==1.0);
  }   

  if(check){
   printf("Resultado correcto\n");
  }else{
   printf("Resultado erroneo\n");
  }
 free(A);
 free(B);
 free(C);
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
