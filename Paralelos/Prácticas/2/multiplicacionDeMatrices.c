#include <pthread.h>
#include<stdio.h>
#include<stdlib.h>
#define ORDENXFILAS 0
#define ORDENXCOLUMNAS 1
#define NUM_THREADS	4

struct thread_data{
    int  thread_id;
    int  sum;
    char *message;
};

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

void barrier(pthread_t *thread[NUM_THREADS], pthread_attr_t *attr){
    long t, rc;
    void *status;
    pthread_attr_destroy(attr);
    for(t=0; t<NUM_THREADS; t++) {
	//rc = pthread_join(thread[t], &status);
	printf("join() is %d\n", thread[t]);
	if (rc) {
	    printf("ERROR; return code from pthread_join() is %d\n", rc);
	    exit(-1);
	}
	printf("Main: completed join with thread %ld having a status of %ld\n",t,(long)status);
    }
}

void *initialize(void *threadid)
{
    long i, j,t, tid;
   tid = (long)threadid;
   printf("Hello World! It's me, thread #%ld!\n", tid);

   for(i=0,t=tid*(N/NUM_THREADS) ;i<N/NUM_THREADS;i++,t++){
       for(j=0;j<N;j++){
	A[t*N+j]=1;
	B[t+j*N]=1;
   }
   pthread_exit(NULL);
}


int main(int argc,char*argv[]){
 double *A,*B,*C;
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


 //Inicializa las matrices A y B en 1, el resultado sera una matriz con todos sus valores en N
   pthread_t thread[NUM_THREADS];
   pthread_attr_t attr;
   int rc;
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);


   for(t=0;t<NUM_THREADS;t++){
     printf("In main: creating thread %ld\n", t);
     rc = pthread_create(&thread[t], &attr, initialize, (void *)t); 
  }  
   
   barrier(&thread, &attr);


 /* //Realiza la multiplicacion */

  timetick = dwalltime();
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			C[i,j]= 0;
		 	for(k=0;k<N;k++){
				C[i,j]=C[i,j]+A[i,k]*B[k,j];
		 	}
		}
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
 return(0);
}
