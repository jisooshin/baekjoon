#include <iostream>
#include <vector>

using namespace std;


void getCount(int target, int* base, vector<int> storage, int* counter){
	if(target== 1){
		*counter = 1;
	} else if(target== 2){
		*counter = 2;
	} else if(target== 3){
		*counter = 4;
	} else if (*base == target){
	} else {
		if (*base == 3){
			*base = *base + 1;
			*counter = *counter + 4;
			storage[1] = 4;
			getCount(target, base, storage, counter);
		} else if (*base == 2){
			*base = *base + 1;
			*counter = *counter + 2;
			storage[0] = 2;
			getCount(target, base, storage, counter);
		} else if (*base == 1){
			*base = *base + 1;
			*counter = *counter + 1;
			getCount(target, base, storage, counter);
		} else {
			*base = *base + 1;
			int tmp = 0;
			tmp = *counter;
			*counter = *counter + storage[0] + storage[1];
			storage[0] = storage[1];
			storage[1] = tmp; 
			getCount(target, base, storage, counter);
		}
	}
}

int main(){
	int numTestCase;
	int input;
	cin >> numTestCase;
	vector<int> testCase;
	testCase.reserve(numTestCase);

	for (int i = 0; i < numTestCase; i++){
		cin >> input;
		testCase.emplace_back(input);
	}

	// vector<int> last(2, 0);
	// int start = 1;
	// int* ptr = &start;
	// int count = 0;
	// int* countPtr = &count;
	// getCount(input, ptr, last, countPtr);
	for (const auto elem: testCase){
		vector<int> last(2, 0);
		int start = 1;
		int* ptr = &start;
		int count = 0;
		int* countPtr = &count;
		getCount(elem, ptr, last, countPtr);
		cout << count << endl;
	}



	return 0;
}