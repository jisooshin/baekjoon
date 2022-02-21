#include <vector>
#include <iostream>

using namespace std;

void merge(vector<int>& vec, vector<int>& v1, vector<int>& v2){
	int v1Size = v1.size();
	int v2Size = v2.size();
	int p1 = 0;
	int p2 = 0;

	while (p1 < v1Size && p2 < v2Size){
		if (v1[p1] < v2[p2]){
			vec.push_back(v1[p1++]);
		} else {
			vec.push_back(v2[p2++]);
		}
	}

	while (p1 < v1Size) {
		vec.push_back(v1[p1++]);
	}
	while (p2 < v2Size) {
		vec.push_back(v2[p2++]);
	}
}

void mergeSort(vector<int>& vec){
	if (vec.size() <= 1){
		return ;
	}
	auto mid = vec.begin() + vec.size() / 2;
	vector<int> v1(vec.begin(), mid);
	vector<int> v2(mid, vec.end());

	mergeSort(v1);
	mergeSort(v2);

	vec.clear();
	merge(vec, v1, v2);

}

int main(){
	vector<int> base { 1, 3, 2, 7, 11, 7, 8, 9 };

	for (const auto elem: base){
		cout << elem << " ";
	} cout << endl;

	mergeSort(base);

	for (const auto elem: base){
		cout << elem << " ";
	} cout << endl;


	return 0;

}