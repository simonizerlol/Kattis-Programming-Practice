#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int counter=0;
	for(int i=0; i < n; i++){
		int t;
		cin >> t;
		if(t<0){
			counter++;
		}
	}
	cout << counter;
	return 0;
}