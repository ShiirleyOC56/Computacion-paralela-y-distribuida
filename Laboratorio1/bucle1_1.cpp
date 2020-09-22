#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<time.h>

#define MAX 1500
using namespace std;

void bucle1(double (*A)[MAX],double x[MAX
	],double y[MAX]){
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			y[i]+=A[i][j]*x[j];
		}
	}
}
void bucle2(double (*A)[MAX],double x[MAX
	],double y[MAX]){
	for(int j=0;j<MAX;j++){
		for(int i=0;i<MAX;i++){
			y[i]+=A[i][j]*x[j];
		}
	}
}
void llenarMatriz(double (*A)[MAX]){
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			A[i][j]=rand()%51;
		}
	}
}
void llenar_arreglo(double x[MAX]){
	for (int i = 0; i < MAX; ++i)
	{
		x[i]=rand()%51;
	}
}
int main(){
	unsigned t0,t1,t2,t3;
	srand(time(NULL));
	cout<<MAX<<endl;
	double A[MAX][MAX],x[MAX],y[MAX];
	llenarMatriz(A);
	llenar_arreglo(x);
	t0=clock();
	bucle1(A,x,y);
	t1=clock();
	double timeb1=(double(t1-t0)/CLOCKS_PER_SEC);
	cout<<"Buble 1 "<<timeb1<<endl;
	t2=clock();
	bucle2(A,x,y);
	t3=clock();
	double timeb2=(double(t3-t2)/CLOCKS_PER_SEC);
	cout<<"Buble 2 "<<timeb2<<endl;

	return 0;

}