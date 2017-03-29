#include <iostream>

using namespace std;

int main(){
	int n;
	//cin >> n;
	while(cin >> n){
		int ctr = 1;
		int seq = 1;
		while(seq%n != 0){
			seq *= 10;
			seq += 1;
			seq = seq%n;
			++ctr;
		}
		cout << ctr << endl;
	}
	return 0;
}
