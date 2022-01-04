#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int get_value(int num_stairs){
	int result { 0 };
	if (num_stairs == 1){
		return 1;
	} else if (num_stairs == 2){
		return 2;
	} else if (num_stairs == 3){
		return 4;
	}
	list<int> base = { 4, 2, 1 };
	for (int i = 3; i < num_stairs; i++){
		result = 0;
		int counter { 0 };
		for (const auto elem: base){
			if (counter == 3){
				break;
			}
			result += elem;
			counter++;
		}
		base.emplace_front(result);
		base.pop_back();
	}
	return result;
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

	for (const auto elem: testCase){
		cout << get_value(elem) << endl;
	}

	return 0;
}