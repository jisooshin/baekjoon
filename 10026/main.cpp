#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <stdio.h>
#include <cstring>

using namespace std;

template <typename T>
void print2d(vector<vector<T>>& v)
{
	cout << "=====================" << endl;
	for(const auto i: v){
		for (const auto j: i){
			cout << j << " ";
		} cout << endl;
	}
	cout << "=====================" << endl;
}

void dfs(
		vector<vector<char>>& base,
		vector<vector<bool>>& visited,
		pair<int, int> startIdx)
{
	vector<pair<int, int>> didj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	stack<pair<int, int>> s;
	s.push(startIdx);
	visited[startIdx.first][startIdx.second];
	// printf("Traverse: %d, %d\n", startIdx.first, startIdx.second);
	
	while ( !s.empty() )
	{
		pair<int, int> targetIdx = s.top();
		char currentChar = base[targetIdx.first][targetIdx.second];
		bool isExistsSub = false;
		for (const auto& elem: didj)
		{
			if (
				targetIdx.first + elem.first < base.size() &&
				targetIdx.first + elem.first >= 0 &&
				targetIdx.second + elem.second < base.size() &&
				targetIdx.second + elem.second >= 0
			)
			{
				if ( base[targetIdx.first + elem.first][targetIdx.second + elem.second] == currentChar &&
					 visited[targetIdx.first + elem.first][targetIdx.second + elem.second] == false )
				{
					s.push({targetIdx.first + elem.first, targetIdx.second + elem.second});
					visited[targetIdx.first + elem.first][targetIdx.second + elem.second] = true; 
					isExistsSub = true;
					// printf("Traverse: %d, %d\n", 
					// 	targetIdx.first + elem.first,
					// 	targetIdx.second + elem.second
					// );
					break;
				}

			}

		}

		if (!isExistsSub){
			s.pop();
		}
	}
}


int main()
{
	int N;
	cin >> N;
	vector<vector<char>> base          (N, vector<char>(N));
	vector<vector<char>> baseCblind    (N, vector<char>(N));
	vector<vector<bool>> visited       (N, vector<bool>(N, false));
	vector<vector<bool>> visitedCblind (N, vector<bool>(N, false));

	for (int i = 0; i < N; i++){
		string st;
		cin >> st;
		for (int j = 0; j < st.size(); j++){
			base[i][j] = st[j];
			if (st[j] == 'R' || st[j] == 'G'){
				baseCblind[i][j] = 'C';
			} else {
				baseCblind[i][j] = st[j];
			}
		}
	}
	int normal { 0 };
	int cblind { 0 };

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (visited[i][j] == 0){
				dfs(base, visited, {i, j});
				normal++;
			}
		}
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (visitedCblind[i][j] == 0){
				dfs(baseCblind, visitedCblind, {i, j});
				cblind++;
			}
		}
	}

	cout << normal << " ";
	cout << cblind << endl;

	return 0;
}