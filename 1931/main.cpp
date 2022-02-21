#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


inline void merge(vector<vector<int>>& vec,
		   vector<vector<int>>& v1,
		   vector<vector<int>>& v2 )
{
	int size1 = v1.size();
	int size2 = v2.size();
	int p1 = 0;
	int p2 = 0;
	while ( p1 < size1 && p2 < size2 ){
		if (v1[p1][1] < v2[p2][1]){
			vec.push_back(v1[p1++]);
		} else if (v1[p1][1] > v2[p2][1]) {
			vec.push_back(v2[p2++]);
		} else {
			if (v1[p1][0] < v2[p2][0]){
				vec.push_back(v1[p1++]);
			} else {
				vec.push_back(v2[p2++]);
			}
		}
	}

	while ( p1 < size1 ) vec.push_back(v1[p1++]);
	while ( p2 < size2 ) vec.push_back(v2[p2++]);
}


inline void mergeSort(vector<vector<int>>& vec){
	if (vec.size() <= 1){
		return;
	}
	auto iter = vec.begin() + vec.size() / 2;
	vector<vector<int>> v1(vec.begin(), iter);
	vector<vector<int>> v2(iter, vec.end());
	mergeSort(v1);
	mergeSort(v2);
	vec.clear();
	merge(vec, v1, v2);
}




int main(){
	ios_base::sync_with_stdio(false);
	int N, start, end;
	cin >> N;
	vector<vector<int>> vec;
	vec.reserve(N);

	for(int i = 0; i < N; i++){
		cin >> start >> end;
		vec.push_back({start, end});
	}

	mergeSort(vec);

	int endTime;
	int count = 0;
	for (int i = 0; i < N; i++){
		if (i == 0){
			count++;
			endTime = vec[i][1];
		} else {
			if (vec[i][0] >= endTime){
				count++;
				endTime = vec[i][1];
				continue;
			}
		}
	}
	cout << count << endl;



	return 0;
}