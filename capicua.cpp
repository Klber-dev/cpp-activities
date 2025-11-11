#include <iostream>


bool Capicua(int num){
	int original = num;
	int inverso = 0;
	
	while(num > 0){
		int digito = num % 10;
		inverso = inverso * 10 + digito;
		num /= 10;
	}
	
	return original == inverso;
}

int main(){
	int numero;
	
	std::cout << "Digite um numero\n";
	std::cin >> numero;
	
	if (Capicua(numero)){
		std::cout << "O numero " << numero << " eh capicua" << std::endl;
	}else{
		std::cout << "O numero " << numero << " eh capicua" << std::endl;
	}
}
