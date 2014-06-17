#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* Time in seconds from some point in the past */
double dwalltime();


int main(int argc,char*argv[]){
    double *A,*B,*C,*W;
 int i,j,k,N;
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
 
  timetick = dwalltime();

  double total = 0;
  double temp = 0;
  
  //Calcula la media ponderada
  for(i=0;i<N;i++){
	for(j=0;j<N;j++){
	   temp += W[i*N+j];
	   total += A[i*N+j] * W[i*N+j];
	}
  }

  total/=temp;

  //Realiza la ecuacion general
  for(i=0;i<N;i++){
	for(j=0;j<N;j++){
		for(k=0;k<N;k++){
			C[i*N+j]=sqrt((pow(A[i*N+j]-total,2))*(pow(B[i*N+j]-total,2)));
		}
	}
  }

  printf("Tiempo en segundos: %f \n", dwalltime() - timetick);

  //Chequea los resultados
  for(i=0;i<N*N;i++){
	check= check&&(C[i]==0.0);
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
