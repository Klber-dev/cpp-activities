#include <iostream>;
using namespace std;

int main(){
	int a[3][5], sl[3];
	int x, y, i;
	
	//Atribuicaoo de valores
	for(x = 0; x < 3; x++){
		for(y = 0; y < 5; y++){
			cout << "Digite o valor para linha " << x+1 << " e coluna " << y+1 << endl;
			cin >> a[x][y]; 
		}
	}
	
	//Imprimir a matriz
	for(x = 0; x < 3; x++){
		for(y = 0; y < 5; y++){
			cout << a[x][y] << "\t";
		}
	cout << endl;
	}
	
	cout << endl;
	for(i = 0; i < 3; i++){
		sl[i] = 0;
		for(y = 0; y < 5; y++){
			sl[i] += a[i][y];
		}
	}		
	
	cout << endl;
	cout << "Resultados:" << endl;
	for(i = 0; i < 3; i ++){
		cout << "linha " << i+1 <<": " << sl[i] << endl;
	}
 
}
