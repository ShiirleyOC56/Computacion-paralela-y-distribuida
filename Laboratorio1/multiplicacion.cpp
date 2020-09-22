#include<iostream>
#include<time.h>
using namespace std;
void llenar_matriz(double **A,int tam){
	int numero;
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			numero=rand()%(20);
			A[i][j]=numero;
		}
	}
}
void imprimir(double **C,int tam){
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			cout<<C[i][j]<<" ";
		}
		cout<<endl;
	}
}
void mutiplicacion(double **A,double **B,double **C,int tam){
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			C[i][j]=0;
			for(int k=0;k<tam;k++){
				C[i][j]=C[i][j]+A[i][k]*B[k][j];
			}
		}
	}
	imprimir(C,tam);
}
void inicializar(double **X,int tam){
	for(int i=0;i<tam;i++){
		X[i]=new double[tam];
	}
}

int main(){
	srand(time(NULL));
	int tam=2;
	//primera matriz
	double** A=new double*[tam];
	inicializar(A,tam);
	llenar_matriz(A,tam);
	//segunda matriz
	double** B=new double*[tam];
	inicializar(B,tam);
	llenar_matriz(B,tam);
	//producto
	double** C=new double*[tam];
	inicializar(C,tam);
	mutiplicacion(A,B,C,tam);

	return 0;
}