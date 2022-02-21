#include <iostream>

using namespace std;

int hanoi(int n){
	if (n == 1){
		return 1;
	} else if (n == 2) {
		return 3;
	}

	return 2 * hanoi(n - 1) + 1;
}

void hanoi2(int n, int start, int mid, int end){
	if ( n == 1 ) {
		printf("%d %d\n", start, end);
	} else {
		hanoi2(n - 1, start, end, mid);
		hanoi2(1, start, mid, end);
		hanoi2(n - 1, mid, start, end);
	}
}

int main(){
	int n;
	cin >> n;
	cout << ( 1 << n ) - 1 << endl;
	hanoi2(n, 1, 2, 3);

	return 0;
}