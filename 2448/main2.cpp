#include <iostream>
#include <cmath>
using namespace std;


char base[6561][6561];

void drawOne(int i, int j){
	for (int r = 0; r < 3; r++){
		for (int c =0; c < 3; c++){
			if(!(c % 3 == 1 && r % 3 == 1)){
				base[r + i][c + j] = '*';
			}
		}
	}
}

void draw(int n, int i, int j){
	if ( n == 3 ){
		drawOne(i, j);
		return;
	}

	draw(n / 3, i, j);
	draw(n / 3, i, j + n / 3);
	draw(n / 3, i, j + 2 * n / 3);
	draw(n / 3, i + n / 3, j);
	draw(n / 3, i + n / 3, j + 2 * n / 3);
	draw(n / 3, i + 2 * n / 3, j);
	draw(n / 3, i + 2 * n / 3, j + n / 3);
	draw(n / 3, i + 2 * n / 3, j + 2 * n / 3);
}


int main(){
	int n;
	cin >> n;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			base[i][j] = ' ';
		}
	}

	draw(n, 0, 0);

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << base[i][j];
		} cout << endl;
	}


	return 0;
}