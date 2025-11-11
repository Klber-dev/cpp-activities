#include <iostream>
using namespace std;

int buscarElemento(int array[], int size, int x, int &contagem) {
	for (int i = 0; i < size; i++) {
   		if (array[i] == x) {
        	contagem++;
    	}	
	}
	
    for (int i = 0; i < size; i++) {
        if (array[i] == x) {
        	return i;
        }
    }
    return -1;
}

int main() {
	int contagem;
    int vetor[10];
    int x;

    cout << "Digite 10 numeros inteiros: " << endl;
    cout << "==========================" << endl;
    for (int i = 0; i < 10; i++) {
    	cout << i+1 << "o numero: ";
        cin >> vetor[i];
    }

    cout << "Digite um numero para verificar se ele existe no vetor: ";
    cin >> x;

    int retorno = buscarElemento(vetor, 10, x, contagem);

    if (retorno == -1) {
        cout << "Valor nao encontrado no vetor.\n";
    } else {
    	if(contagem > 1){
        cout << "o valor foi encontrado no vetor " << contagem << " vezes" << endl;
        }else{
        	cout << "o valor foi encontrado no vetor " << contagem << " vez" << endl;
		}
    }

    return 0;
}	
