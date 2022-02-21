#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;


template <typename T>
void merge(vector<T>& vec, vector<T>& v1, vector<T>& v2){
	size_t size1 = v1.size();
	size_t size2 = v2.size();
	size_t p1 = 0;
	size_t p2 = 0;

	while( p1 < size1 && p2 < size2 ){
		if (v1[p1] > v2[p2]){
			vec.push_back(v2[p2++]);
		} else {
			vec.push_back(v1[p1++]);
		}
	}

	while ( p1 < size1 ) vec.push_back(v1[p1++]);
	while ( p2 < size2 ) vec.push_back(v2[p2++]);
}

template <typename T>
void mergeSort(vector<T>& vec){
	if (vec.size() <= 1){
		return;
	}
	auto iter = vec.begin() + (vec.size() / 2);

	vector<T> v1(vec.begin(), iter);
	vector<T> v2(iter, vec.end());

	mergeSort(v1);
	mergeSort(v2);
	vec.clear();
	merge(vec, v1, v2);
}


int main(){
	int N;
	cin >> N;
	vector<int> base;
	base.reserve(N);

	for (size_t i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		base.push_back(tmp);
	}


	mergeSort(base);

	int tmp = 0;
	int sum = 0;
	for (auto& elem: base){
		elem = elem + tmp;
		tmp = elem;
		sum += elem;
	}

	cout << sum << endl;
	return 0;
}