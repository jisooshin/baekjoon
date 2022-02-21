#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#define I first
#define J second

using namespace std;
typedef pair<int, int> Coord;

char maze    [10][10];
bool visited [10][10];
Coord red, blue, hole;

struct Info
{
	Coord red, blue;    // 변화하는 red, blue  위치
	string route;		// route 정보
	int cost;			// 몇번 움직였는지
};

enum DirUtil
{
	LEFT_MORE_FORWARD,
	RIGHT_MORE_FORWARD,
	NOT_MATCHING
};


// function declaration
Coord td(char dir);
Coord moveBall(Coord target, Coord other, char direction, bool visitCheck);
DirUtil leftIsMoreThanRight(Coord target, Coord other, char direction);
Info findWays();
void printInfo(Info& info);

// ************************************************************************* //
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



	Info result = findWays();
	if (result.cost > 10) {
		printf("%d\n", -1);
	} else {
		printf("%d\n", result.cost);
	}

	if (result.route.size() > 0)
		printf("%s\n", result.route.c_str());

	return 0;
}
// ************************************************************************* //


Info findWays()
{
	Info result({red, blue, "", -1});
	queue<Info> q;
	q.push({red, blue, "", 0});
	visited[red.I][red.J] = true;
	
	vector<pair<Coord, char>> directionLoop {
		{ td('L'), 'L' },
		{ td('R'), 'R' },
		{ td('U'), 'U' },
		{ td('D'), 'D' }
	};
	
	// printInfo(q.front());
	while(!q.empty())
	{
		Info target = q.front();
		q.pop();
		if (target.blue == hole) { continue; }
		if (target.red == hole)
		{
			if (target.blue == hole)
			{
				target.route = "";
				target.cost = -1;
			} 
			return target;
		}

		printf("\n\n\n");
		printf("< target Queue >\n");
		printInfo(target);
		printf("***********************\n");

		for (const auto direction: directionLoop)
		{
			char  dirChar = direction.second;
			Coord targetCoord = { target.red.I + td(dirChar).I, target.red.J + td(dirChar).J};
			Coord targetBlueCoord = { target.blue.I + td(dirChar).I, target.blue.J + td(dirChar).J};

			Info candidateInfo = target;

			// red ball이 움직이지 않고, blue ball이 움직일 수 있다면 queue에 넣어보기 
			if (
				(visited[targetCoord.I][targetCoord.J] == false) && (maze[targetCoord.I][targetCoord.J] != '#')
			)
			{
				if (leftIsMoreThanRight(candidateInfo.red, candidateInfo.blue, dirChar) == DirUtil::LEFT_MORE_FORWARD) {
					candidateInfo.red  = moveBall(candidateInfo.red, candidateInfo.blue, dirChar, true);
					candidateInfo.blue = moveBall(candidateInfo.blue, candidateInfo.red, dirChar, false);
				} else {
					candidateInfo.blue = moveBall(candidateInfo.blue, candidateInfo.red, dirChar, false);
					candidateInfo.red  = moveBall(candidateInfo.red, candidateInfo.blue, dirChar, true);
				}

				if (target.red == candidateInfo.red) { continue; }              // red ball이 움직이지 않았으면 queue에 
				candidateInfo.route.push_back(dirChar);
				candidateInfo.cost++;
				printf("<=== Queued ===>\n");
				printInfo(candidateInfo);
				q.push(candidateInfo);
			}
		}
	}
	return result;
}


Coord moveBall(Coord target, Coord other, char direction, bool visitCheck)
{
	Coord result;
	Coord dir = td(direction);
	while (true)
	{
		Coord tmp = target;
		tmp.I += dir.I;
		tmp.J += dir.J;

		if (tmp == hole)   				return hole;
		if (tmp == other)               return target;
		if (maze[tmp.I][tmp.J] == '#') 	return target;

		if (visitCheck) {
			// if (visited[tmp.I][tmp.J])  return target;
			visited[tmp.I][tmp.J] = true;
		}
		target = tmp;
		result = target;
	}
	return result;
}


Coord td(char dir)
{
	Coord result;
	if      (dir == 'L') result = {  0 , -1 };
	else if (dir == 'R') result = {  0 ,  1 };
	else if (dir == 'U') result = { -1 ,  0 };
	else if (dir == 'D') result = {  1 ,  0 };
	else throw(invalid_argument("Not supported."));
	return result;
}

DirUtil leftIsMoreThanRight(Coord target, Coord other, char direction)
{

	DirUtil result;
	Coord dir = td(direction);
	target.I += dir.I;
	target.J += dir.J;
	other.I += dir.I;
	other.J += dir.J;
	if (direction == 'U' || direction == 'D') {
		if (target.J != other.J) return DirUtil::NOT_MATCHING;
		if (direction == 'U')
		{
			if (target.I < other.I)  return DirUtil::LEFT_MORE_FORWARD;
			else 					 return DirUtil::RIGHT_MORE_FORWARD;
		} else {
			if (target.I > other.I)  return DirUtil::LEFT_MORE_FORWARD;
			else 					 return DirUtil::RIGHT_MORE_FORWARD;
		}
	} else {
		if (target.I != other.I) return DirUtil::NOT_MATCHING;

		if (direction == 'L') {
			if (target.J < other.J)  return DirUtil::LEFT_MORE_FORWARD;
			else 					 return DirUtil::RIGHT_MORE_FORWARD;
		} else {
			if (target.J > other.J)  return DirUtil::LEFT_MORE_FORWARD;
			else 					 return DirUtil::RIGHT_MORE_FORWARD;

		}
	}
}


void printInfo(Info& info)
{
	printf("\tRed: (%d, %d) | Blue: (%d, %d) | route: %s | cost: %d\n", info.red.I, info.red.J, info.blue.I, info.blue.J, info.route.c_str(), info.cost);
}