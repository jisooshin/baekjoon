#include <iostream>
using namespace std;
char board[3100][6200];

void drawOne(int i, int j){
	board[i][j] = '*';
	board[i + 1][j - 1] = '*';
	board[i + 1][j + 1] = '*';
	for (int k = 0; k < 5; k++){
		board[i + 2][j - 2 + k] = '*';
	}

} 

void draw(int n, int i, int j){
	if (n == 3){
		drawOne(i, j);
		return;
	}
	draw(n / 2, i, j);
	draw(n / 2, i + n / 2, j - n / 2);
	draw(n / 2, i + n / 2, j + n / 2);


}

int main(){
	// 6
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= n * 2; j++){
			board[i][j] = ' ';
		}
	}
	// 6, 0, 5
	// 3, 0, 5
	// 3, 3, 2
	// 3, 3, 8
	draw(n, 0, n - 1);
	
	for (int i = 0; i < n; i++){
		for(int j = 0; j < 2 * n - 1; j++){
			cout << board[i][j];
		} cout << endl;
	}

	return 0;
}