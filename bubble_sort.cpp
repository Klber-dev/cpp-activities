#include <iostream>
#include <vector>
using namespace std;

void bubblesort(vector<int>& vetor) {
    int tamanho = vetor.size();
    int temp = 0;

    for (int i = 0; i < tamanho; i++) {
        cout << "\n--- Passada " << i + 1 << " ---" << endl;

        for (int j = 1; j < tamanho - i; j++) {

            // Mostrar comparação atual
            cout << "Comparando vetor[" << j - 1 << "]=" << vetor[j - 1]
                 << " e vetor[" << j << "]=" << vetor[j] << endl;

            if (vetor[j - 1] > vetor[j]) {
                // Trocar elementos
                temp = vetor[j - 1];
                vetor[j - 1] = vetor[j];
                vetor[j] = temp;

                // Mostrar vetor após a troca
                cout << "Trocou ";
                for (int k = 0; k < tamanho; k++) {
                    cout << vetor[k] << " ";
                }
                cout << endl;
            }
        }

        // Mostrar vetor após a passada
        cout << "Fim da passada " << i + 1 << ": ";
        for (int k = 0; k < tamanho; k++) {
            cout << vetor[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> vetor = {5, 3, 8, 1};

    cout << "Vetor inicial: ";
    for (int v : vetor) cout << v << " ";
    cout << endl;

    bubblesort(vetor);

    cout << "\nVetor final ordenado: ";
    for (int v : vetor) cout << v << " ";
    cout << endl;

    return 0;
}
