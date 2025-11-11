#include <iostream>
using namespace std;

void invert(int x[]){
	for (int i = 0; i < 5/2; i++){
		int aux = x[i];
		x[i] = x[4-i];
		x[4 - i] = aux;
	}
}
	
int main(){
	int vetor[] = {1, 2, 3, 4, 5};
	
	cout << "Vetor atual: ";
	for(int i = 0; i < 5; i++){
		cout << vetor[i] << " ";
	} 
	
	invert(vetor);
	
	cout << "Vetor invertido: ";
	for(int i = 0; i < 5; i++){
		cout << vetor[i] << " ";
	}
	
}
