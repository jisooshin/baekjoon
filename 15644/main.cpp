#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
#include <string>
#define I first 
#define J second 

using namespace std;

typedef pair<int, int> COORD;
char maze    [10][10];
bool visited [10][10];
COORD red, blue, hole;
struct INFO 
{
	COORD red, blue;
	string route = "";
	int cost = 0;
};


COORD td(char dir);
COORD getBlueCoord(COORD currentBlue, COORD currentRed, char dir);
INFO findWays();
void printINFO(INFO target)
{
	printf("============================\n");
	printf("Red coord : %d, %d\n", target.red.I, target.red.J);
	printf("Blue coord : %d, %d\n", target.blue.I, target.blue.J);
	printf("Route: %s\n", target.route.c_str());
	printf("Cost : %d\n", target.cost);
	printf("============================\n");

}

int main()
{
	int N, M;
	cin >> N >> M;
	

	memset(*visited, false, sizeof(visited));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> maze[i][j];
			if      (maze[i][j] == 'R') red  = {i, j};
			else if (maze[i][j] == 'B') blue = {i, j};
			else if (maze[i][j] == 'O') hole = {i, j};
			else if (maze[i][j] == '#') visited[i][j] = true;
		}
	}
	// printf("======before=====\n");
	// for (int i = 0; i < N; i++)
	// {
	// 	for (int j = 0; j < N; j++)
	// 	{
	// 		cout << visited[i][j] << " ";
	// 	} cout << endl;
	// }

	INFO result = findWays();

	// printf("======after=====\n");
	// for (int i = 0; i < N; i++)
	// {
	// 	for (int j = 0; j < N; j++)
	// 	{
	// 		cout << visited[i][j] << " ";
	// 	} cout << endl;
	// }

	if (result.cost == 0)
	{
		cout << -1 << endl;
	} else {
		cout << result.cost << endl;
	}
	if (result.route.size() > 0)
	{
		cout << result.route << endl;
	}
	return 0;
}

INFO findWays()
{
	INFO result;
	vector<pair<COORD, char>> baseLoop {
		{ td('L'), 'L' },
		{ td('R'), 'R' },
		{ td('U'), 'U' },
		{ td('D'), 'D' }
	};
	queue<INFO> q;
	q.push({ red, blue, "", 0 });
	visited[red.I][red.J] = true;

	while (!q.empty())
	{
		INFO target = q.front();
		// printf("Red ball move: (%d, %d)\n", target.red.I, target.red.J);
		// printf("Blue ball move: (%d, %d)\n", target.blue.I, target.blue.J);
		q.pop();

		if (target.cost > 10)
		{
			result.cost = -1;
			result.route = "";
			return result;
		}

		if (target.red == hole)                                                 // red ball이 hole에 들어간 경우라면 함수 종료하고 target 을 반환
		{ 
			if (getBlueCoord(target.blue, {0, 0}, target.route.back()) == hole)
			{
				target.route = "";
				target.cost = -1;
			}
			return target; 
		}								
		if (target.blue == hole) { continue; }                                  // blue ball이 hole에 들어갈경우에는 loop를 빠져나와 다른 direction 을 찾아보게 한다. b

		for (const auto dir: baseLoop)
		{
			COORD targetCoord = { target.red.I + dir.first.I, target.red.J + dir.first.J };

			if(
				(visited[targetCoord.I][targetCoord.J] == false) &&  			// 방문한적 없어야하고 
			  	(maze[targetCoord.I][targetCoord.J] != '#')      &&      		// 벽이 아니면서
				(getBlueCoord(target.blue, target.red, dir.second) != targetCoord) // blue ball과 겹치면 안되는  blue 와 겹쳐도 되지만, blue가 이동할 공간이 있어야함 
			)
			{	
				// 위의 조건들을 일단 queue에 넣자.	
				INFO candidate;
				candidate.route = target.route;
				candidate.cost = target.cost;
				candidate.red = targetCoord;
				candidate.blue = getBlueCoord(target.blue, candidate.red, dir.second);
				if (
					(candidate.route.back() != dir.second) ||
					(targetCoord == hole)
				)
				{
					if (candidate.route.back() != dir.second)
					{
						candidate.cost++;
						candidate.route.push_back(dir.second);
					}
				}
				visited[targetCoord.I][targetCoord.J] = true;
				q.push(candidate);
			}

		}

	}
	return  result;
}

COORD getBlueCoord(COORD currentBlue, COORD currentRed, char dir)
{
	while(1)
	{
		if (maze[currentBlue.I + td(dir).I][currentBlue.J + td(dir).J] == '#')
		{
			break;
		}
		else if (currentBlue == hole)
		{
			return hole;
		}
		else if (currentBlue == currentRed)
		{
			currentBlue.I -= td(dir).I;
			currentBlue.J -= td(dir).J;
			return currentBlue;
		}
		// 그리고 Red가 막았을때도 체크해야함
		currentBlue.I += td(dir).I;
		currentBlue.J += td(dir).J;
	}
	return currentBlue;
}

COORD td(char dir)
{
	COORD result;
	if      (dir == 'L') result = {  0 , -1 };
	else if (dir == 'R') result = {  0 ,  1 };
	else if (dir == 'U') result = { -1 ,  0 };
	else if (dir == 'D') result = {  1 ,  0 };
	else throw(invalid_argument("Not supported."));
	return result;
}

/*
5 5 
#####
#...#
#BO.#
#R..#
#####



5 5 
#####
#.R.#
#.O.#
#.B.#
#####

4 4
####
#.O#
#BR#
####

4 4
####
#.O#
#RB#
####

6 10
##########
#..B.....#
#........#
#...O....#
#......R.#
##########

현재 안되는 것
7 6
######
######
####.#
#.R#.#
#.#.##
#O.B.#
######

4 6
######
#..###
#OBR##
######


*/