#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	while(n != -1){
		int previousT = 0;
		int miles = 0;
		for(int i = 0; i < n; i++){
			int s, t;
			cin >> s >> t;
			miles = miles + s * abs((previousT - t));
			previousT = t; // save it for the next loop
			
		}
		cout << miles << " miles" << endl; // end of the line, goes to a new line
	cin >> n;
	}
	return 0;
}