#include <iostream>
using namespace std;
int main(){
	int H, M;
	cin >> H >> M;
	
	M = (M - 45 + 60);
	if(M/60 == 0){
		H = H -1;
	}
	else{
		M = M % 60;
	}
	if(H<0){
		H = H + 24;
	}

	cout << H << " " << M;
	return 0;
}