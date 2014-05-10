#include<stdio.h>
#include<stdlib.h>

//Dimension por defecto de las matrices
int N=100;

//Para calcular tiempo
double dwalltime(){
        double sec;
        struct timeval tv;

        gettimeofday(&tv,NULL);
        sec = tv.tv_sec + tv.tv_usec/1000000.0;
        return sec;
}


int main(int argc,char*argv[]){
    double *A,*B,*C,a,b;
 int i,j,k;
 int check=1;
 double timetick;

 //Controla los argumentos al programa
 if ((argc != 2) || ((N = atoi(argv[1])) <= 0) )
  {
    printf("\nUsar: %s n\n  n: Dimension de la matriz (nxn X nxn)\n", argv[0]);
    exit(1);
  }

 //Aloca memoria para las matrices
  A=(double*)malloc(sizeof(double)*N*N);
  B=(double*)malloc(sizeof(double)*N*N);
  C=(double*)malloc(sizeof(double)*N*N);
  
  for(i=0;i<N;i++){
   for(j=0;j<N;j++){
       A[i,j] = 1;
       B[i,j] = 1;
   }
  }   

 //Realiza el calculo

  timetick = dwalltime();

  for(i=0;i<N;i++){
      for(j=0;j<N;j++){
	  a += A[i,j];
	  b += B[i,j];
	}
  }
  a /= (N*N);
  b /= (N*N);
  double average = a*b;
  for(i=0;i<N;i++){
     for(j=0;j<N;j++){
	 C[i,j]= 0;
 	for(k=0;k<N;k++){
            C[i,j]=C[i,j]+(A[i,j]*B[k,j]*average);
	}
     }
  }
    

  //printf("Tiempo en segundos %f\n", dwalltime() - timetick);

 //Verifica el resultado
  for(i=0;i<N;i++){
   for(j=0;j<N;j++){
       check=check&&(C[i,j]==N);
   }
  }   

  if(check){
      //printf("Multiplicacion de matrices resultado correcto\n");
      printf("%f\n",dwalltime() - timetick);
  }else{
   printf("Multiplicacion de matrices resultado erroneo\n");
  }

 free(A);
 free(B);
 free(C);
 return(0);
}
