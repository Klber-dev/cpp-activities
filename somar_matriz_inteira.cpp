#include <iostream>
using namespace std;

main(){
	int x, y, res = 0,
	m[5][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 
	13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
	
//	for(x = 0; x < 5; x++){
//		for(y = 0; y < 5; y++){
//			res += m[x][y];
//		}
//	}
	
//	cout << res;


	for(y = 0; y < 5; y++){
		res += m[4][y];
	}

	
	cout << res;
}
