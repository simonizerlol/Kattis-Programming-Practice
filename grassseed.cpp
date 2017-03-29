#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	double c;
	int l;
	cin >> c >> l;
	double sum = 0;
	for(int i=0; i < l; i++){
		double width, length;
		cin >> width >> length;
		sum += width*length;
	}
	printf("%.8f", c*sum);
	return 0;
}