#include <iostream>
using namespace std;

typedef struct{
	string nome;
	int nivel;
	int hp;
	int atk;
}ficha;

void criar_ficha(ficha personagem[], int &quantidade, int tamanho){
	if (quantidade >= tamanho) {
		cout << "Limite de personagens atingido." << endl;
		return;
	}

	cout << "\n=== Novo Personagem ===\n" << endl;

	cout << "Nome do personagem: " << endl;
	cin.ignore(1000, '\n');
	getline(cin, personagem[quantidade].nome);

	cout << "Nivel atual do personagem: " << endl;
	cin >> personagem[quantidade].nivel;

	cout << "Quantidade de vida do personagem: " << endl;
	cin >> personagem[quantidade].hp;

	cout << "Poder de ataque do personagem: " << endl;
	cin >> personagem[quantidade].atk;

	quantidade++;
}

void aumentar_nivel(ficha personagem[], int &pontos, int tamanho){
	string nome;
	int upgrade = 0;
	int atributo = 0;
	
	cout << "\n=== Level Up ===\n" << endl;
	
	cout << "Digite o nome do personagem que deseja evoluir: ";
	cin.ignore(1000, '\n');
	getline(cin, nome);
	
	bool encontrado = false;
	for(int i = 0; i < tamanho; i++){
		if(nome == personagem[i].nome){
			encontrado = true;
			cout << "\n=== Personagem encontrado! ===\n" << endl;
			
			cout << "Qual atributo deseja melhorar? [1] para vida, [2] para ataque" << endl;
			cin >> atributo;
				
			if(atributo == 1){
				cout << "Quanto de vida deseja adicionar?" << endl;
				cin >> upgrade;
				
				personagem[i].hp += upgrade;
				pontos -= upgrade;
				
				cout << "Upgrade feito com sucesso!" << endl;
				break;
			}else if(atributo == 2){
				cout << "Quanto de ataque deseja adicionar?" << endl;
				cin >> upgrade;
				
				personagem[i].atk += upgrade;
				pontos -= upgrade;
				
				cout << "Upgrade feito com sucesso!" << endl;
				break;
			}else{
				cout << "Valor invalido" << endl;
				break;
			}
		}
	}
	if (!encontrado) {
		cout << "Personagem não encontrado." << endl;
	}
}

void batalhar(ficha personagem[], int &pontos, int tamanho){
	string lutador;
	string oponente;
	int p1 = -1;
	int p2 = -1;
	
	cout << "Digite o nome do lutador: " << endl;
	cin.ignore(1000, '\n');
	getline(cin, lutador);
	
	for(int i = 0; i < tamanho; i++){
		if(lutador == personagem[i].nome){
			p1 = i;
			break;
		}
	}
	
	if (p1 == -1) {
		cout << "Lutador não encontrado!" << endl;
		return;
	}
	
	cout << "Digite o nome do oponente: " << endl;
	getline(cin, oponente);
	
	for(int i = 0; i < tamanho; i++){
		if(oponente == personagem[i].nome){
			p2 = i;
			break;
		}
	}
	
	if (p2 == -1) {
		cout << "Oponente não encontrado!" << endl;
		return;
	}
	
	cout << "Resultado da batalha: ";
	
	if(personagem[p1].atk > personagem[p2].atk){
		cout << "Voce venceu!" << endl;
		pontos += 3;
		cout << "+3 pontos." << endl;
	}else if(personagem[p1].atk == personagem[p2].atk){
		cout << "Empate" << endl;
		cout << "+1 ponto." << endl;
		pontos++;
	}else{
		cout << "Perdeste" << endl;
		cout << "Nao ganhou nenhum ponto." << endl;
	}
	
}
		 
int main(){
	const  int TAMANHO = 3;
	ficha personagem[TAMANHO];
	int pontos = 0;
	int quantidade = 0;
	int escolha = 0;
	
	do{	
	cout<<"Esolha uma das opções:"<<endl;
	cout<<"1 = Criar personagem"<<endl;
	cout<<"2 = Upar Nivel de Personagem"<<endl;
	cout<<"3 = Simular Batalha entre Personagens"<<endl;
	cout<<"4 = FECHAR PROGRAMA"<<endl;
	cin>>escolha;
	
	switch(escolha){
		case 1:
			criar_ficha(personagem, quantidade, TAMANHO);
			break;
		case 2:
			aumentar_nivel(personagem, pontos, TAMANHO);
			break;
		case 3:
			batalhar(personagem, pontos, TAMANHO);
			break;
		default:
			cout<<"Opção invalida"<<endl;
			break;
		}
			
	}while(escolha != 4);
}
