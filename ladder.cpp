#include <iostream>
#include <math.h> // for sin fumction
using namespace std;
int main(){
	int h, v;
	int hypotenuse;
	cin >> h >> v;
	hypotenuse = h/sin(v*M_PI/180.0)+1; // +1 to round up
	cout << hypotenuse << endl;
	return 0;
}