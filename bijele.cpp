#include <iostream>
using namespace std;
int main(){
	int k, q, r, b, kn, p;
	cin >> k >> q >> r >> b >> kn >> p;
	
	if(k > 1 || k < 1){
		k = 1-k;
	}
	else{
		k = 0;
	}
	if(q > 1 || q < 1){
		q = 1-q;
	}
	else{
		q = 0;
	}
	if(r > 2 || r < 2){
		r = 2 - r;
	}
	else{
		r = 0;
	}
	if(b > 2 || b <2){
		b = 2 - b;
	}
	else{
		b = 0;
	}
	if(kn > 2 || kn < 2){
		kn = 2-kn;
	}
	else{
		kn = 0;
	}
	if(p > 8 || p < 8){
		p = 8 - p;
	}
	else{
		p = 0;
	}
	
	cout << k << " " << q << " " << r << " " << b << " " << kn << " " << p;
}