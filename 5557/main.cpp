#include <iostream>
#include <vector>


using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> inputs;
	vector<vector<long long>> dp(N, vector<long long>(21, 0));

	for (int i = 0; i < N; i++){
		int tmp;
		cin >> tmp;
		inputs.push_back(tmp);
	}

	dp[0][inputs[0]] = 1;
	for (int i = 1; i < N - 1; i++){
		for (int val = 0; val <= 20; val++){
			if (dp[i - 1][val] > 0){
				if (val + inputs[i] <= 20) {
					dp[i][val + inputs[i]] += dp[i - 1][val];
				} 
				if (val - inputs[i] >= 0){
					dp[i][val - inputs[i]] += dp[i - 1][val];
				}
			}
		}
	}

	for (const auto i: dp){
		for (const auto j: i){
			cout << j << " ";
		} cout << endl;
	}

	return 0;
}