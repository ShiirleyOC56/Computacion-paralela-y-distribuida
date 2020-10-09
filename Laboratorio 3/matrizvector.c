#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "timer.h"
#include <unistd.h>

/* Variables globales*/
int thread_count,n,m;
double *matrix,*resultado,*vec;

double timeval_diff(struct timeval *a, struct timeval *b)
{
  return (double)(a->tv_sec + (double)a->tv_usec/1000000) - (double)(b->tv_sec + (double)b->tv_usec/1000000);
}

void Llenarmatriz(double * matriz, int fila, int col)
{
    for (int i=0;i<(fila*col);i++) 
    {
        *(matriz + i)=1+(double)(10*random()/(RAND_MAX+1.0));
    }
    return;
}
void Mostrarmatriz(double *matriz, int fila, int col)
{
    for (int i = 0; i < fila; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            printf("%7g ",matriz[i*col+j]);
        }
        printf("\n");
    }
    return;
}
void* Pth_mat_vect(void* rank)
{
	long my_rank=(long) rank;
	int local_m=m/thread_count;
	int my_first_row=my_rank*local_m;
	int my_last_row=(my_rank+1)*local_m -1;

	for(int i=my_first_row;i<=my_last_row;i++)
	{
		resultado[i]=0.0;
		for(int j=0;j<n;j++)
			resultado[i]+=matrix[i*n+j]*vec[j];
	}
	return NULL;
}
int main (int argc, char * argv[])
{
	long thread;
	pthread_t* thread_handles;
	double ini, end;
	thread_count=strtol(argv[1],NULL,10);
	thread_handles=malloc (thread_count*sizeof(pthread_t));
	/*Separar memoria */
	vec=malloc(n*sizeof(double));
    resultado=malloc(m*sizeof(double));
    matrix=malloc(m*n*sizeof(double));
    /*Llenar matriz*/
    Llenarmatriz(matrix,m,n);
    Llenarmatriz(vec,1,n);
    
  	GET_TIME(ini);
	for (thread=0;thread<thread_count;thread++)
		pthread_create(&thread_handles[thread],NULL,Pth_mat_vect,(void*)thread);
	for (thread=0;thread<thread_count;thread++)
		pthread_join(thread_handles[thread],NULL);
	
  	GET_TIME(end);
  	printf("Time = %e seconds\n",end - ini);

  	/*Liberar memoria*/
  	free(thread_handles);
	free(matrix);
	free(vec);
	free(resultado);
	return 0;
}