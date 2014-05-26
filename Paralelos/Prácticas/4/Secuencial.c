#include<stdio.h>
#include<stdlib.h>

/* Time in seconds from some point in the past */
double dwalltime();


int main(int argc,char*argv[]){
    double *A,*B;
 double min,max,avg=0; 
 int i,j,N;
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

  //Inicializa la matriz 
  for(i=0;i<N;i++){
   for(j=0;j<N;j++){
	A[i*N+j]= 1.0;
   }
  }   
 
 timetick = dwalltime();
 min = A[1*N+1];
 max = A[1*N+1];
  for(i=0;i<N;i++){
   for(j=0;j<N;j++){
       if (A[i*N+j]<min) min=A[i*N+j];
       if (A[i*N+j]<max) max=A[i*N+j];
       avg+=A[i*N+j];
   }
  }

  avg/=N;

  for(i=0;i<N;i++){
   for(j=0;j<N;j++){
       if (A[i*N+j]<avg) B[i*N+j]=min;
       if (A[i*N+j]>avg) B[i*N+j]=max;
       if (A[i*N+j]==avg) B[i*N+j]=avg;
   }
  }


    printf("Tiempo en segundos: %f \n", dwalltime() - timetick);

  //Chequea los resultados
  for(i=0;i<N;i++){
   for(j=0;j<N;j++){
	check= check&&(B[i*N+j]==1.0);
   }
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
