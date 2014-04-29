#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#define ORDENXFILAS 0
#define ORDENXCOLUMNAS 1
#define N_THREADS 4
//Dimension por defecto de las matrices
int N=100;
double average;
double *A,*B,*C;

struct thread_data{
    int  tid;
    int  result_a;
    int  result_b;
};

//Para calcular tiempo
double dwalltime(){
        double sec;
        struct timeval tv;

        gettimeofday(&tv,NULL);
        sec = tv.tv_sec + tv.tv_usec/1000000.0;
        return sec;
}

void *t_average(void *arg){
    int i,j,t;
    struct thread_data *t_data;
    t_data = (struct thread_data*) arg;
    t_data->result_a=0;
    t_data->result_b=0;
    for(i=0,t=t_data->tid*(N/N_THREADS);i<(N/N_THREADS);i++,t++){
	for(j=0;j<N;j++){
	    t_data->result_a += A[t,j];
	    t_data->result_b += B[t,j];
	}
    }
}


void *prod_matrix(void *arg){
    int i,j,k;
    struct thread_data *t_data;
    t_data = (struct thread_data*) arg;
    int evaluation = (int) (1+t_data->tid)*(N/N_THREADS);
    for(i=(int) t_data->tid*(N/N_THREADS);i<evaluation;i++){
     for(j=0;j<N;j++){
	C[i,j]= 0;
 	for(k=0;k<N;k++){
            C[i,j]+=A[i,k]*B[k,j]*average;
	}
     }
  }
}


int main(int argc,char*argv[]){
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

  // Defino los thread
  pthread_t thread[N_THREADS];
  struct thread_data data[N_THREADS];
  
  pthread_attr_t attr;
  int rc;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  timetick = dwalltime();

  for(i=0; i<N_THREADS; i++)
      {
	  data[i].tid=i;
	  rc = pthread_create(&thread[i], &attr, t_average, (void *) &data[i]);
	  if (rc){
	      printf("ERROR; return code from pthread_create() is %d\n", rc);
	      exit(-1);
	  }
}
  double a,b = 0;
  for(i=0; i<N_THREADS; i++)
      {
	  pthread_join(thread[i], NULL);
	  a += data[i].result_a;
	  b += data[i].result_b;
      }

  average = (a/(N*N))*(b/(N*N));
  
  for(i=0; i<N_THREADS; i++)
      {
	  rc = pthread_create(&thread[i], &attr, prod_matrix, (void *)&data[i]);
	  if (rc){
	      printf("ERROR; return code from pthread_create() is %d\n", rc);
	      exit(-1);
	  }
      }
  
  for(i=0; i<N_THREADS; i++)
      {
	  pthread_join(thread[i], NULL);
      }
    

 printf("Tiempo en segundos %f\n", dwalltime() - timetick);

 //Verifica el resultado
  for(i=0;i<N;i++){
   for(j=0;j<N;j++){
	//check=check&&(getValor(C,i,j,ORDENXFILAS)==N);
	check=check&&(C[i,j]==N);
   }
  }   

  if(check){
   printf("Multiplicacion de matrices resultado correcto\n");
  }else{
   printf("Multiplicacion de matrices resultado erroneo\n");
  }

 free(A);
 free(B);
 free(C);
 pthread_exit(NULL);
 return(0);
}
