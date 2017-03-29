#include <iostream>
using namespace std;
int main(){
	int g1,g2,g3,g4;
	int i=1, n=5;
	int sum;
	int winningPts=0;
	int winner;
	for(i; i <= 5; i++){
		cin >> g1 >> g2 >> g3 >> g4;
		sum = g1+g2+g3+g4;
		if(sum > winningPts){
			winningPts = sum;
			winner = i;
		}
	}
	cout << winner << " " << winningPts << endl;
	return 0;
}