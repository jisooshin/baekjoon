#include <list>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
int main(){
	vector<int> a;
	a.reserve(10);

	unordered_set<int> b;
	for (int i = 0; i < 10; i++){
		if (i%2==0){
			a.emplace_back(1);
			b.emplace(1);
		} else {
			a.emplace_back(2);
			b.emplace(2);
		}
	}

	cout << a.size() << " " << b.size() << endl;


	return 0;
}