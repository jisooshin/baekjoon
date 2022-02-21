#include <iostream>
#include <vector>

using namespace std;


int main()
{
	short N, S, M;
	cin >> N >> S >> M;
	vector<short> V;
	V.reserve(N);
	for (int i = 0; i < N; i++){
		short tmp;
		cin >> tmp;
		V.push_back(tmp);
	}

	vector<vector<short>> dp(M + 1, vector<short>(N, 0));

	for (int order = 0; order < N; order++)
	{
		bool isAllZeros = true;
		for (int volume = 0; volume <= M; volume++)
		{
			if (order == 0) {
				if (S + V[order] <= M) { 
					dp[S + V[order]][order] = 1; 
					isAllZeros = false;
				}
				if (S - V[order] >= 0) {
					dp[S - V[order]][order] = 1; 
					isAllZeros = false;
				}
			} else {
				if (dp[volume][order - 1] > 0){
					if (volume + V[order] <= M) { 
						dp[volume + V[order]][order] = 1;
						isAllZeros = false;
					}
					if (volume - V[order] >= 0) {
						dp[volume - V[order]][order] = 1; 
						isAllZeros = false;
					}
				}
			}
			
		}
		if (isAllZeros) {
			cout << -1 << endl;
			break;
		}
	}

	for (int i = M; i >= 0; i--)
	{
		if (dp[i][N - 1] > 0) {
			cout << i << endl;
			break;
		}
	}



	// cout << "=============== " << endl;
	// for(int i = 0; i < dp.size(); i++){
	// 	cout << i << "\t";
	// 	for (const auto j: dp[i]){
	// 		cout << j << " ";
	// 	} cout << endl;
	// }

	
	return 0;
}