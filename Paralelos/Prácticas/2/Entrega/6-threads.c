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
    int  start;
    int  evaluation;
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
    int i,in,j,a=0,b=0;
    struct thread_data *t_data;
    t_data = (struct thread_data*) arg;
    for(i=t_data->start;i<t_data->evaluation;i++){
	in=i*N;
	for(j=0;j<N;j++){
	    a += A[in+j];
	    b += B[in+j];
	}
    }
    t_data->result_a=a;
    t_data->result_b=b;

}


void *prod_matrix(void *arg){
    int i,j,k,in,jn,tmp;
    struct thread_data *t_data;
    t_data = (struct thread_data*) arg;
    for(i=t_data->start;i<t_data->evaluation;i++){
	in=i*N;
     for(j=0;j<N;j++){
	 jn=j*N;
	 tmp=0;
 	for(k=0;k<N;k++){
            tmp+=A[in+k]*B[k+jn]*average;
	}
	C[in+j]=tmp;
     }
  }
}


int main(int argc,char*argv[]){
 int i,in,j,k;
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

  // Defino los thread
  pthread_t thread[N_THREADS];
  struct thread_data data[N_THREADS];
  
  pthread_attr_t attr;
  int rc,jobs_thread=N/N_THREADS;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  timetick = dwalltime();

  for(i=0; i<N_THREADS; i++)
      {
	  data[i].tid=i;
	  data[i].start = (int) i*jobs_thread;
	  data[i].evaluation = (int) (1+i)*jobs_thread;
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
