#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<vector<int>> mat;

void bSearch(int min, int max);
bool bfs(int diff, int minVal, int maxVal);

int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	int min = 200;
	int max = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vector<int> tmpV;
		for (int j = 0; j < n; j++)
		{
			int tmp;
			cin >> tmp;
			min = tmp > min ? min : tmp;
			max = tmp > max ? tmp : max;
			tmpV.push_back(tmp);
		}
		mat.push_back(tmpV);
	}
	bSearch(min, max);
	return 0;
}

void bSearch(int min, int max)
{
	int left  = 0;
	int right = max;
	int mid;
	int lastVal;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (bfs(mid, min, max))
		{
			lastVal = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << left << endl;

}

bool bfs(int diff, int minVal, int maxVal)
{	 
	bool result = false;
	for (int exp = minVal; exp <= maxVal; exp++)
	{
		int min = exp;
		int max = exp + diff;
		// printf("Start with min = %d, max = %d\n", min, max);
		vector<pair<int, int>> mvWay { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
		vector<vector<bool>> visited (mat.size(), vector<bool>(mat.size(), false));
		queue<pair<int, int>> q;
		if (mat[0][0] < min || mat[0][0] > max)
		{
			result = false;
			continue;
		}
		// printf("visited: (%d, %d)\n", 1, 1);
		visited[0][0] = true;
		q.push({0, 0});

		while (!q.empty())
		{
			pair<int, int> targetCoord = q.front();
			q.pop();
			for (const auto& way: mvWay)
			{
				pair<int, int> currCoord = {targetCoord.first + way.first, targetCoord.second + way.second};
				// 최소한 밖으로는 튀어나가지 않게 하기
				if (currCoord.first  < 0 || currCoord.first  >= mat.size() || 
				    currCoord.second < 0 || currCoord.second >= mat.size()) 
				{
					continue;
				}
				// currCoord 의 값이 min max 사이어야만 함

				if
				(
					(mat[currCoord.first][currCoord.second] <= max && mat[currCoord.first][currCoord.second] >= min) &&
					(visited[currCoord.first][currCoord.second] == false)
				)
				{
					q.push({currCoord.first, currCoord.second});
					visited[currCoord.first][currCoord.second] = true;
					// printf("visited: (%d, %d)\n", currCoord.first + 1, currCoord.second + 1);
					if (currCoord.first == mat.size() - 1 && currCoord.second == mat.size() - 1)
					{
						while(!q.empty()) q.pop();
						break;
					}
				}

			}

		}
		result = visited[mat.size() - 1][mat.size() - 1];
		if (result) break;
	}

	return result;
}