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
 int in,jn,i,j,k,tmp;
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
      in=i*N;
   for(j=0;j<N;j++){
       A[in+j] = 1;
       B[in+j] = 1;
   }
  }   

 //Realiza el calculo

  timetick = dwalltime();

  for(i=0;i<N;i++){
      in=i*N;
      for(j=0;j<N;j++){
	  a += A[in+j];
	  b += B[in+j];
	}
  }
  double average = (a/(N*N))*(b/(N*N));
  //  int tmp;
  for(i=0;i<N;i++){
      in=i*N;
     for(j=0;j<N;j++){
	 jn=j*N;
	 tmp=0;
 	for(k=0;k<N;k++){
            tmp+=(A[in+j]*B[k+jn]*average);
	}
	 C[in+j]= tmp;
     }
  }
    

  //printf("Tiempo en segundos %f\n", dwalltime() - timetick);

 //Verifica el resultado
  for(i=0;i<N;i++){
      in=i*N;
   for(j=0;j<N;j++){
       check=check&&(C[in+j]==N);
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
