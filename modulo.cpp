#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
	int i = 1;
	int n;
	int array[11]; // 10 elements
	for(i; i <= 10; i++){
		cin >> n;
		array[i] = n%42;
	}
	// returns the number of distinct values
	const size_t len = sizeof(array) / sizeof(array[0]); // size_t is a type guaranteed to hold any array index.

    unordered_set<int> s(array, array + len); // gets the set of unique objects

    cout << s.size()-1 << endl;
	return 0;
}