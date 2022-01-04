#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;
int main(){
	int N, r, c;
	scanf("%d %d %d", &N, &r, &c);

	vector<vector<int>> container(r+1, vector<int>(r+1, 0));

	int targetN { -1 };
	int modulo;
	int m;
	for (int row = 0; row <= r; row++){
		for (int col = 0; col <= r; col++){
			targetN = -1;
			if (col == 0){
				if (row == 0){

				} else {
					for (int expn = N - 1; expn > 0; expn--){
						if ((int)row % (int)pow(2, expn) == 0){
							targetN = expn;
							break;
						}
					}
					if (targetN == -1){
						container[row][col] = container[col][row] * 2;
					} else {
						container[row][col] = container[col][row] + int(pow(2, 2 * targetN));
					}

				}

			} else {
				for (int expn = N - 1; expn >= 0; expn--){
					modulo = (int)col % (int)pow(2, expn);
					if (modulo == col){
					} else {
						targetN = expn;
						break;	
					}
				}
				m = col - (int)pow(2, targetN);
				container[row][col] = container[row][m] + pow(2, 2 * targetN);
			}
		}
	}
	cout << container[r][c] << endl;
	cout << " ====== " << endl;

	return 0;
}