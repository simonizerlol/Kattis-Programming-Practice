#include <iostream>
using namespace std;

int main()
{
	int i, j;
	cin >> i >> j;
	if(i > 0 && j > 0){
		cout << "1";
	}
	else if(i > 0 && j < 0){
		cout << "4";
	}
	else if(i < 0 && j > 0){
		cout << "2";
	}
	else{
		cout << "3";
	}
	return 0;
}