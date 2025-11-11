#include <iostream>
using namespace std;

typedef struct{
	string rua;
	string bairro;
	string cidade;
	string estado;
	int cep;
}local;

typedef struct{
	string nome;
	string estadoCivil;
	string sexo;
	local endereco; 
	float salario;
	int idade;
	int rg;
	int cpf;
	int fone;
}dados;

void LowerCase(string &texto){
	for(int i = 0; i < (int)texto.size(); i++){
		if (texto[i] >= 'A' && texto[i] <= 'Z'){
			texto[i] = texto[i] + 32;
		}
	}
};

void DataInsert(dados cadastro[], int tamanho){
	for(int i = 0; i < tamanho; i++){
		cout << "Digite seu nome:" << endl;
        cin.ignore(); 
        getline(cin, cadastro[i].nome);

        cout << "Digite sua idade:" << endl;
        cin >> cadastro[i].idade;
        cin.ignore(); 

        cout << "Digite seu estado civil:" << endl;
        getline(cin, cadastro[i].estadoCivil);
        LowerCase(cadastro[i].estadoCivil);

        cout << "Digite seu sexo:" << endl;
        getline(cin, cadastro[i].sexo);
        LowerCase(cadastro[i].sexo);

        cout << "Digite sua rua:" << endl;
        getline(cin, cadastro[i].endereco.rua);

        cout << "Digite seu bairro:" << endl;
        getline(cin, cadastro[i].endereco.bairro);

        cout << "Digite sua cidade:" << endl;
        getline(cin, cadastro[i].endereco.cidade);

        cout << "Digite seu estado:" << endl;
        getline(cin, cadastro[i].endereco.estado);
        LowerCase(cadastro[i].endereco.estado);

        cout << "Digite seu CEP:" << endl;
        cin >> cadastro[i].endereco.cep;
        cin.ignore(); 

        cout << "Digite seu salário:" << endl;
        cin >> cadastro[i].salario;
        cin.ignore(); 

        cout << "Digite seu RG:" << endl;
        cin >> cadastro[i].rg;
        cin.ignore(); 

        cout << "Digite seu CPF:" << endl;
        cin >> cadastro[i].cpf;
        cin.ignore(); 

        cout << "Digite seu telefone:" << endl;
        cin >> cadastro[i].fone;
        cin.ignore();
	}

}

void BiggerAge(dados cadastro[], int tamanho, int &maiorIdade){
	for(int i = 0; i < tamanho; i++){
	if(cadastro[i].idade > maiorIdade){
		maiorIdade = cadastro[i].idade;
		}
	}
}

void MaleAmount(dados cadastro[], int tamanho, int &qntMasculino){
	for(int i = 0; i < tamanho; i++){
	if(cadastro[i].sexo == "masculino") qntMasculino ++;
	}
}

void BiggerSalary(dados cadastro[], int tamanho, int &maiorSalario, int salarioMinimo){
	for(int i = 0; i < tamanho; i++){
		if(cadastro[i].salario > salarioMinimo) maiorSalario++;
	}
}

int main(){
	
	dados cadastro[2];
	const int TAMANHO = sizeof(cadastro)/sizeof(cadastro[0]);
	const int SALARIO_MINIMO = 1417;
	int maiorIdade = 1, qntMasculino = 0, maiorSalario, rg;
	
	DataInsfert(cadastro, TAMANHO);
	BiggerAge(cadastro, TAMANHO, maiorIdade);
	MaleAmount(cadastro, TAMANHO, qntMasculino);
	BiggerSalary(cadastro, TAMANHO, maiorSalario, SALARIO_MINIMO);
	
	cout << "===================================" << endl;
	cout << "Maior idade cadastrada: " << maiorIdade << endl;
	cout << "Pessoas de sexo masculino: " << qntMasculino << endl;
	cout << "Pessoas com mais de um salario minimo: " << maiorSalario << endl;
	cout << "===================================" << endl;
	
	cout << "Digite o RG para encontrar um usuário" << endl;
	cin >> rg;
	
	for(int i = 0; i < TAMANHO; i ++){
		if(rg == cadastro[i].rg){
			cout << "Pessoa encontrada:" << endl;
			cout << cadastro[i].nome << endl;
			cout << cadastro[i].idade << endl;
			cout << cadastro[i].estadoCivil << endl;
			cout << cadastro[i].sexo << endl;
			cout << "Salario: ." << cadastro[i].salario << endl;
			cout << "CPF: " << cadastro[i].cpf << endl;
			cout << "Telefone: " << cadastro[i].fone << endl;
			cout << "CEP: " << cadastro[i].endereco.cep << endl;
			break;
		}
	}
}
