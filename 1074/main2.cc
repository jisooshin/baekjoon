
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <limits>

// recursive하게 top-down
using namespace std;

int getValue(int r, int c, int sizeN){
	int targetN, modulo, m;
	if ((r == 0) && (c == 0)){
		return 0;
	} else {
		if (c == 0){

			targetN = -1;

			for (int expn = sizeN - 1; expn > 1; expn--){
				if (((r & (r - 1)) == 0) && (r > 1) && (r == pow(2, expn))){
					targetN = expn;
					break;
				}
			}
			if (targetN == -1){
				return 2 * getValue(c, r, sizeN);
			} else {
				return (int)pow(2, 2 * targetN) + getValue(c, r, sizeN);
			}

		} else {
			targetN = -1;
			for (int expn = sizeN - 1; expn >= 0; expn--){
				modulo = (int)c % (int)pow(2, expn);
				if (modulo == c){
				} else {
					targetN = expn;
					break;
				}
			}
			m = c - (int)pow(2, targetN);
			return getValue(r, m, sizeN) + pow(2, 2 * targetN);


		}
	}
}


int main(){
	int n, r, c;
	scanf("%d %d %d", &n, &r, &c);
	cout << getValue(r, c, n) << endl;

	return 0;
}