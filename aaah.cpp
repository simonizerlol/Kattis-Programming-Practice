#include <iostream>
using namespace std;
int main(){
	string i, j;
	while(cin >> i >> j){
		if(i.length() >= j.length()){
			cout << "go\n";
		}
		else{
			cout << "no\n";
		}
	}
	return 0;
}