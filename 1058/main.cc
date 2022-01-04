#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <numeric>
#include <list>
#include <algorithm>

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

	for (int i = 0; i < size; i++){
		// 각 Vector
		for (int j = 0; j < size; j++){
			if (container[i][j] == 1){
				// i번째 vector에서의 index_list뽑기
				index_list.emplace_back(j);
			}
		}

		int sum { static_cast<int>(index_list.size()) };
		for (auto it = index_list.begin(); it != index_list.end(); it++){
			// 대상이 되는 vector 값 합
			sum += accumulate(container[*it].begin(), container[*it].end(), 0);
			for (auto nit = index_list.begin(); nit != index_list.end(); nit++){
			 	if ((container[*it][*nit] == 1) && (*it != *nit)) {
			 		sum--;
			 	}
			}

		}
		sum = sum - static_cast<int>(index_list.size());

		cout << sum << endl;
		result_container.emplace_back(sum);
		index_list.clear();
	}
	// cout << *max_element(result_container.begin(), result_container.end()) << endl;
	return 0;
}