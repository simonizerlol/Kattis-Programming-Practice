#include <iostream>
using namespace std;
int main(){
	int x, y, n;
	cin >> x >> y >> n;
	for(int i = 1; i <= n; i++){
		if(i%x == 0 && i%y == 0 && i != 1){
			cout << "FizzBuzz\n";	
		}
		else if(i%y == 0){
			cout << "Buzz\n";		
		}
		else if (i%x == 0){
			cout << "Fizz\n";	
		}
		else{
			cout << i << "\n";
		}
		//cout << i << "\n";
	}
	return 0;
}