#include <iostream>
using namespace std;

double pot(int base, int expoente) {

    if (expoente == 0) {
        return 1;
	}else{
        return base * pot(base, expoente - 1);
    }
}

double fat(int n){
	if (n == 1){
		return 1;
	}else{
		return n * fat(n-1);
	}
}

double algebra(float calc, int x, int el){
	if (el == 0){
		return 1;
	}else{
		calc = (pot(x, el)/fat(el));
		
		return calc + algebra(calc, x, el - 1);
	}
}

int main(){
	cout << algebra(0,2,15);
}


