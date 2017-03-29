#include <iostream>
using namespace std;
int main(){
	int x, n, i, dataSpent;
	cin >> x >> n;
	int sum = 0;
	for(i=0; i < n; i++){
		cin >> dataSpent;
		sum += dataSpent;
	}
	cout << x+x*n-sum << endl;
	return 0;
}