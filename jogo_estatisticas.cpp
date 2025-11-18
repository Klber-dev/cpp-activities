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

    for(int i = 0; i < 3; i++){
        cout << "Tente advinhar um numero entre 1 e 10: ";
        cin >> resposta;
        cout << endl;
    
        if(resposta == numero){
            cout << "Voce venceu com " << p.tentativas+1 << " tentativas!\n";
            p.venceu = true;
            cout << endl;
            break;
        }else if(i < 2){
            cout << "Errou!, você tem mais " << 2 - i << " tentativas. Tente novamente.\n";
            p.tentativas++;
        }else{
            cout << "Voce perdeu! O numero era " << numero << ".\n";
            p.venceu = false;
        }
    }
        
/* 	do{
    
        cout << "Tente advinhar um numero entre 1 e 10: ";
        cin >> resposta;
        cout << endl;
    
        if(resposta == numero){
            cout << "Voce venceu com " << p.tentativas+1 << " tentativas!\n";
            p.venceu = true;
            cout << endl;
        }else{
            cout << "Errou! Tente novamente.\n";
            p.tentativas++;
        }
        
    }while(p.venceu == false); */
}

void registrarPartida(partida partidas[], int &qtd, partida p){
    partidas[qtd-1] = p;
}

double taxaVitoria(partida partidas[], int qtd, int jogador){
    int vitoria = 0;

    for(int i = 0; i < qtd; i++){
        if(partidas[i].numeroJogador == jogador && partidas[i].venceu == true){
            vitoria++;
        }
    }
    if(vitoria == 0){
        return 1;
    } else {
        double taxa = (vitoria / (double)qtd) * 100;
        return taxa;
    }

}

int melhorDesempenho(partida partidas[], int qtd){
    int melhor = 4;
    int indice = -1;
    for( int i = 0; i < qtd; i++){
        if(partidas[i].tentativas < melhor && partidas[i].venceu == true){
            melhor = partidas[i].tentativas;
            indice = i;
        }
    }

    return indice;
}

int main(){
    partida partidas[50];
    partida p;
    int qtd = 0;
    int action;
    
    do{	
        int jogador = 0;
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
            jogar(p);
            qtd++;
            registrarPartida(partidas, qtd, p);
            cout << endl;
            break;
        case 2:
            cout << "Digite o numero do jogador: ";
            cin >> jogador;

            if(taxaVitoria(partidas, qtd, jogador) == 1){
                cout << "Nenhuma vitoria registrada ainda.\n\n";
            } else {
                cout << "Taxa de vitoria: " << taxaVitoria(partidas, qtd, jogador) << "%\n\n";
            }
            break;
        case 3:
            if(melhorDesempenho(partidas, qtd) == -1){
                cout << "Nenhum desempenho registrado ainda.\n\n";
            } else {
                int indice = melhorDesempenho(partidas, qtd);
                cout << "Melhor desempenho:\n";
                cout << "Numero do jogador: " << partidas[indice].numeroJogador << "\n";
                cout << "Tentativas: " << partidas[indice].tentativas + 1 << "\n";
                cout << "Data: " << partidas[indice].data << "\n\n";
            }
            cout << endl;
            break;
    }	
        
    }while(action != 4);

    return 0;
}
