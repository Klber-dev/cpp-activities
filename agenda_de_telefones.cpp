#include <iostream>
using namespace std;

typedef struct{
	int DDD;
	int fone;
}contato;

typedef struct {
	string rua;
	int numero;
	string complemento;
	string bairro;
	int cep;
	string cidade;
	string estado;
	string pais; 
}local;

typedef struct{
	int mes;
	int ano;
	int dia;
}nascimento;

typedef struct {
	string nome;
	string email;
	local endereco;
	contato telefone;
	nascimento aniversario;
	string observacao;
} cadastro;

void cadastrarPessoa(cadastro agenda[], int &quantidade) {
    cout << "\n=== CADASTRO DE NOVA PESSOA ===\n";

    cout << "Digite o nome: ";
    cin.ignore();
    getline(cin, agenda[quantidade].nome);

//    cout << "Digite o e-mail: ";
//    getline(cin, agenda[quantidade].email);
//
//    cout << "\n--- Endereco ---\n";
//    cout << "Rua: ";
//    getline(cin, agenda[quantidade].endereco.rua);
//
//    cout << "Numero: ";
//    cin >> agenda[quantidade].endereco.numero;
//    cin.ignore();
//
//    cout << "Complemento: ";
//    getline(cin, agenda[quantidade].endereco.complemento);
//
//    cout << "Bairro: ";
//    getline(cin, agenda[quantidade].endereco.bairro);
//
//    cout << "CEP: ";
//    cin >> agenda[quantidade].endereco.cep;
//    cin.ignore();
//
//    cout << "Cidade: ";
//    getline(cin, agenda[quantidade].endereco.cidade);
//
//    cout << "Estado: ";
//    getline(cin, agenda[quantidade].endereco.estado);
//
//    cout << "Pais: ";
//    getline(cin, agenda[quantidade].endereco.pais);
//
//    cout << "\n--- Telefone ---\n";
//    cout << "DDD: ";
//    cin >> agenda[quantidade].telefone.DDD;
//    cout << "Número: ";
//    cin >> agenda[quantidade].telefone.fone;
//    cin.ignore();
//
    cout << "\n--- nascimento de Aniversario ---\n";
    cout << "Dia: ";
    cin >> agenda[quantidade].aniversario.dia;
    cout << "Mes: ";
    cin >> agenda[quantidade].aniversario.mes;
    cout << "Ano: ";
    cin >> agenda[quantidade].aniversario.ano;
    cin.ignore();
//
//    cout << "\nObservaçao: ";
//    getline(cin, agenda[quantidade].observacao);

    cout << "\nCadastro realizado com sucesso!\n";

    quantidade++;
}

void buscarNome(cadastro agenda[], int tamanho, string nome){
	bool encontrado = false;
	
	for(int i = 0; i < tamanho; i++){
		if(nome == agenda[i].nome){
			encontrado = true;
			
            cout << "\n=== Usuario Encontrado ===\n";
            cout << "Nome: " << agenda[i].nome << endl;
            cout << "E-mail: " << agenda[i].email << endl;

            cout << "\n--- Endereço ---\n";
            cout << "Rua: " << agenda[i].endereco.rua << endl;
            cout << "Numero: " << agenda[i].endereco.numero << endl;
            cout << "Complemento: " << agenda[i].endereco.complemento << endl;
            cout << "Bairro: " << agenda[i].endereco.bairro << endl;
            cout << "CEP: " << agenda[i].endereco.cep << endl;
            cout << "Cidade: " << agenda[i].endereco.cidade << endl;
            cout << "Estado: " << agenda[i].endereco.estado << endl;
            cout << "País: " << agenda[i].endereco.pais << endl;

            cout << "\n--- Telefone ---\n";
            cout << "(" << agenda[i].telefone.DDD << ") " << agenda[i].telefone.fone << endl;

            cout << "\n--- nascimento de Aniversario ---\n";
            cout << agenda[i].aniversario.dia << "/"
                 << agenda[i].aniversario.mes << "/"
                 << agenda[i].aniversario.ano << endl;

            cout << "\nObservacao: " << agenda[i].observacao << endl;
            cout << "===========================\n";
		}
		
	}
	
}

void buscarAniversario(cadastro agenda[], int tamanho, int dia, int mes){
	for(int i = 0; i < tamanho; i++){
		if(dia == agenda[i].aniversario.dia && mes == agenda[i].aniversario.mes){
			cout << "\n=== Aniversariantes ===\n";
			cout << agenda[i].nome << " " << dia << "/" << mes << endl;
		}
	}
}

void removerCadastro(cadastro agenda[], int &quantidade, string nome, string email){
    bool encontrado = false;

    for (int i = 0; i < quantidade; i++) {
        if (agenda[i].nome == nome && agenda[i].email == email) {
            encontrado = true;

            for (int j = i; j < quantidade - 1; j++) {
                agenda[j] = agenda[j + 1];
            }

            quantidade--;
            cout << "\nCadastro removido\n";
            break;
        }
    }

    if (!encontrado) {
        cout << "\nUsuário não encontrado\n";
    }
}

void ordenar(cadastro agenda[], int quantidade){
	cadastro temp;
    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = i + 1; j < quantidade; j++) {
            if (agenda[i].nome > agenda[j].nome) {
                temp = agenda[i];
                agenda[i] = agenda[j];
                agenda[j] = temp;
            }
        }
    }
}


int main(){
	const int TAMANHO = 100;
	cadastro agenda[TAMANHO];
	int instrucao = 0;
	int quantidade = 0;
	string nome, email;
	int dia, mes;
	
	//MENU PRINCIPAL:
	//1 - cadastrarPessoa() --ordenar()
	//2 - buscarNome()
	//3 - buscarAniversario()
	//4 - removerCadastro()
	
	do{
        cout << "1 - Cadastrar Pessoa\n";
        cout << "2 - Buscar Nome\n";
        cout << "3 - Buscar Aniversario\n";
        cout << "4 - Remover Cadastro\n";
        cout << "5 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> instrucao;
        cout << endl;
        
		switch(instrucao){
			case 1:
				system("cls");
				if (quantidade < TAMANHO){
				cadastrarPessoa(agenda, quantidade);
				ordenar(agenda, quantidade);
				}else {
					cout << "Agenda cheia!\n";
				}
				break;
				
			case 2:
				if ( quantidade == 0){
					system("cls");
					cout << "Nenhum usuario cadastrado \n\n";
				}else{
				system("cls");					
				cout << "Digite o nome que deseja procurar: ";
				cin.ignore();
				getline(cin, nome);
				
				buscarNome(agenda, quantidade, nome);
				
				cout << endl;
				}
				break;
			case 3:
				if ( quantidade == 0){
					system("cls");
					cout << "Nenhum usuario cadastrado \n\n";
				}else{
					system("cls");
					cout << "Digite o dia: ";
					cin >> dia;
					cout << "Digite o mes: ";
					cin >> mes;
					cout << endl;
					buscarAniversario(agenda, TAMANHO, dia, mes);
				}
				break;
			case 4:
				if ( quantidade == 0){
					system("cls");
					cout << "Nenhum usuario cadastrado \n\n";
				}else{
					system("cls");
					cout << "Digite o nome do usuario que deseja retirar: ";
					cin.ignore();
					getline(cin, nome);
					cout << "Digite o e-mail do usuario que deseja retirar: ";
					cin.ignore();
					getline(cin, email);
					removerCadastro(agenda, quantidade, nome, email);
				};
				
			}
				
	}while(instrucao != 5);
	
	return 0;
}