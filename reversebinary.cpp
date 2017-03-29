#include <iostream>
#include <string>  
#include <algorithm> // for reverse the sting
using namespace std;
int main(){
	int n;
	cin >> n;
	int d=0;
	string originalBinary = "";
	int r;
	// convert decimal to binary
	while(true){
		d = n/2;
		r = n%2;
		n = d;
		originalBinary += std::to_string(r);
		if(d == 1){
			originalBinary += std::to_string(d);
			break;
		}
	}
	// reverse the binary string
	//reverse(originalBinary.begin(), originalBinary.end());
	int num = stoi(originalBinary); // convert string back to integer
	
	int bin, rem, base = 1, dec = 0;
	while(num > 0){
		rem = num % 10;
		dec = dec + rem * base;
		base = base * 2;
		num = num / 10;
	}
	cout << dec << endl;
	return 0;
}
// this program works but it's too slow (time limit exceptions)
// runtime: exponential