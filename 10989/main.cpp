#include <stdio.h>


int main(){
	int N;
	int tmp;
	scanf("%d", &N);
	int base[10001] = { 0 };


	for (size_t i = 0; i < N; i++) {
		scanf("%d", &tmp);
		base[tmp]++;
	}

	for (int i = 0; i < 10001; i++){
		if (base[i] != 0){
			for (int j = 0; j < base[i]; j++){
				printf("%d\n", i);
			}

		}
	}

	return 0;
}