#include <iostream>
using namespace std;
int main(){
	char s[51]; // at most 50 characters
	int a=1, b=0, c=0;
	cin >> s;
	//cout << s;
	for(int i=0; s[i]!='\0'; i++){
		if(s[i]=='A'){
			swap(a,b);  
		} 
        else if(s[i]=='B'){
			swap(b,c);
		}  
        else{
			swap(a,c);
		}  
	}        
    if(a){
		cout << 1;
	} 
    else if(b){
		cout << 2;
	}  
    else{
		cout << 3;
	}   
	return 0;
}