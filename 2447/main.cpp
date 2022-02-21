#include <iostream>
using namespace std;


void printStar(int x, int y, int num){
	if ((x / num) % 3 == 1 && ( y / num ) % 3 == 1){
		cout << " ";
	} else if (num / 3 == 0){
		cout << "*"	;
	} else {
		printStar(x, y, num / 3);
	}

}

int main() {
    int num;
    cin >> num;
	if (num % 3 != 0){
		return 0;
	}

	for( int y = 0; y < num; y++){
		for (int x = 0; x < num; x++){
			printStar(y, x, num);
		}
		cout << endl;
	}


}