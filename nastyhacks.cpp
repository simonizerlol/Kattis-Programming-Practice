#include <iostream>
using namespace std;
int main()
{	
	int n;
	int ctr = 0;
	cin >> n;
	while(ctr < n){
		int r, e, c;
		cin >> r >> e >> c;
		if(e-c == r){
			cout << "does not matter\n";
		}
		else if(e-c > r){
			cout << "advertise\n";
		}
		else{
			cout << "do not advertise\n";
		}
		ctr++;
	}
	return 0;
}