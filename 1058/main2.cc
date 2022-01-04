#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <numeric>
#include <list>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main(){
	int size;
	cin >> size;
	vector<vector<int>> container(size, vector<int>(size, 0));

	string inputString;
	for(int ci = 0; ci < size; ci++){
		cin >> inputString;
		for (int i = 0; i < inputString.length(); i++){
			if (inputString[i] == 'Y'){
				container[ci][i] = 1;
			}
		}
	}


	vector<int> result_container;
	result_container.reserve(size);
	list<int> index_list;
	unordered_set<int> unique_container;

	for (int i = 0; i < size; i++){
		// 각 Vector
		for (int j = 0; j < size; j++){
			if (container[i][j] == 1){
				index_list.emplace_back(j);
			}
		}


		for (auto it = index_list.begin(); it != index_list.end(); it++){
			unique_container.emplace(*it);
			for (int idx = 0; idx < size; idx++){
				if ((container[*it][idx] == 1) && (idx != i)){
					unique_container.emplace(idx);
				}
			}	
		}
		result_container.emplace_back(unique_container.size());
		index_list.clear();
		unique_container.clear();
	}
	cout << *max_element(result_container.begin(), result_container.end()) << endl;
	return 0;
}