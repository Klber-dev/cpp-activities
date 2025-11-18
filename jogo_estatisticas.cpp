#include <iostream>
using namespace std;

typedef struct{
	int numeroJogador;
	int tentativas;
	bool venceu;
	string data; 
}partida;

void jogar(partida &p){
	int numero = rand() % 10 + 1;
	int resposta;
	
	
	cout << "Digite seu numero de jogador para iniciar o jogo: ";
	cin >> p.numeroJogador;
	cout << "Digite a data atual [--/--/--]: ";
	cin >> p.data;
	cout << endl;
		
	do{
	
		cout << "Tente advinhar um numero entre 1 e 10: ";
		cin >> resposta;
		cout << endl;
	
		if(resposta == numero){
			cout << "Voce venceu com " << p.tentativas+1 << " tentativas!\n";
			p.venceu = true;
			cout << endl;
		}else{
			system("cls");
			cout << "Errou! Tente novamente.\n";
			p.tentativas++;
		}
		
	}while(p.venceu == false);
}

void registrarPartida(partida partidas[], int &qtd, partida p){
	for(int i = 0; i < qtd; i++){
		partidas[i] = p;
	}
	
	qtd++;
}

int main(){
	partida partidas[3];
	partida p;
	int qtd = 0;
	int action;
	
	
	do{	
	p.tentativas = 0;
	p.venceu = false;
	
		cout << "1 - Jogar\n";
        cout << "2 - Taxa de vitoria\n";
        cout << "3 - Melhor desempenho\n";
        cout << "4 - Sair\n";
        cin >> action;
        cout << endl;
		
	switch(action){
		case 1:
			system("cls");
			jogar(p);
			registrarPartida(partidas, qtd, p);
			cout << endl;
			break;
		case 2:
			for(int i = 0; i < qtd; i++){
			cout << partidas[i].numeroJogador << endl;
			}
			break;
	}	
		
	}while(action != 4);

	return 0;
}
