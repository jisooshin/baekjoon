#include <iostream>
using namespace std;

char base[10000][10000];

void printStar(int n, int i, int j) {
	if (n == 1){
		base[i][j] = '*';
	} else {
		for(int r = i; r < i + 4 * n - 3; r++){
			for(int c = j; c < j + 4 * n - 3; c++){
				if (r == i || r == i + ((4 * (n - 1)))){
					base[r][c] = '*';
				}
				if (c == j || c == j + ((4 * (n - 1)))){
					base[r][c] = '*';
				}
			}
		}
		printStar(n - 1, i + 2, j + 2);
	}
}

int main(){
	int n;
	cin >> n;

	for (int i = 0; i < 1 + ( 4 * (n - 1)); i++){
		for (int j = 0; j < 1 + ( 4 * (n - 1)); j++){
			base[i][j] = ' ';
		}
	}
	
	printStar(n , 0, 0);

	for (int i = 0; i < 1 + ( 4 * (n - 1)); i++){
		for (int j = 0; j < 1 + ( 4 * (n - 1)); j++){
			cout << base[i][j];
		} cout << endl;
	}


	
	return 0;
}