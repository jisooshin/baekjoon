#include <stdio.h>
#include <algorithm>

int main(){
	int N;
	scanf("%d", &N);
	int base[N];

	for (int i = 0; i < N; i++){
		scanf("%d", &base[i]);
	}



	for (int i = 0; i < N - 1; i++){
		int tmp;
		for (int j = i + 1; j < N; j++)	{
			if (base[i] > base[j]){
				tmp = base[i];
				base[i] = base[j];
				base[j] = tmp;
			}
		}
	}


	for (int i = 0; i < N; i++)	{
		printf("%d ", base[i]);
	}


	return 0;
}