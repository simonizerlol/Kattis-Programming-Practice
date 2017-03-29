// COMP 321 A3 Q1 Peragrams
// Name: Simon Hsu
// ID: 260610820
// Date: 2017.02.11
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// convert string to char array 
char StringToChar(string x){
  char a[1];
  // c_str() returns a const char* that points to a null-terminated string
  strncpy(a, x.c_str(), sizeof(a));
  return a[0];
}

int main() {
	// initialize variable to receive string input
	string s;
	cin >> s;
	
	// initialize an array to be zero at first
	int array[26];
	for(int i = 0; i < 26; i++){
		array[i] = 0;
	}
	
	// count the occurence of each letter in s using the array we initialized
	int string_length = s.length();
	for(int i = 0; i < string_length; i++){
		// substr(a, b) returns a newly constructed string object, 
		// a = position it starts
		// b = length of the specify string
		char c = StringToChar(s.substr(i, 1));
		array[c - 'a']++; //'a' is 97 in decimal
	}
	
	// count the number of odd occurences and increment the counter
	int counter = 0;
	for(int i = 0; i < 26; i++){
		if(array[i] % 2 != 0){
			counter++;
		}
	}
	
	// if counter is less than or equal to 1, no letter need to be removed
	// else return counter-1 
	if(counter <= 1){
		cout << 0 << "\n";
	}
	else{
		cout << counter - 1 << "\n";
	}
	return 0; // end of program
}
