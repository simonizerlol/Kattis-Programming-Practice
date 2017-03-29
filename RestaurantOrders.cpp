// COMP 321 A4 Q1 Restaurant Orders
// Name: Simon Hsu
// ID: 260610820
// Date: 2017.02.21
#include <bits/stdc++.h>

using namespace std;

// initialize the input variables
int n, c[100], m; // given 1 <= n <= 100
int counter, caseNumber;
int ordersMemory[100][300000], sVisit[100][300000];  // given 1 <= m <= 1000, given 1 <= s <= 30000

// dynamic programming problem
int checkOrders(int i, int s){
	// base cases
	if(i == n){
		return 0; // exit success
	} 
	if(s == 0){
		return 1; // exit fail
	}
	if(sVisit[i][s] == caseNumber){
		return ordersMemory[i][s]; 
	}
	sVisit[i][s] = caseNumber;

	// dont choose
	ordersMemory[i][s] = checkOrders(i+1, s); // recursion
	// more than one selections, choose
	if(s - c[i] >= 0){
		ordersMemory[i][s] = ordersMemory[i][s] + checkOrders(i, s - c[i]);
	}
	// prevent error
	if(ordersMemory[i][s] > 1000){
		ordersMemory[i][s] = 1000;
	}
	return ordersMemory[i][s];
}

void printOutput(int i, int s){
	// if there is nothing to print then nothing gets printed
	if(s <= 0 || i == n){
		return;
	}
	
	if(checkOrders(i+1, s) ==  1){
		if(counter != 0){
			printf("%d ", i+1);
		}
		printOutput(i+1, s);
	}

	if(s - c[i] >= 0){
		if(checkOrders(i, s - c[i]) == 1){
			printf("%d ", i+1);
			printOutput(i, s - c[i]);
		}	
	}
	counter++;
}

int main(){
	// first line scan for number of items on the menu
	scanf("%d\n", &n);
	
	// second line scan for the cost of each items on the menu
	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);
	}
	
	// third line scan for the number of ordered placed.
	scanf("%d\n", &m);
	
	// usage: void * memset ( void * ptr, int value, size_t num )
	// Sets the first num bytes of the block of memory pointed by ptr to the specified value (interpreted as an unsigned char).
	// eg. str[]="hello"
	// memset(str,"-",5) gives str[]="-----"
	memset(sVisit, -1, sizeof(sVisit)); // default case: -1
	for(int i = 0; i < m; i++){
		int s;
		// fourth line scan for the total cost of all ordered items
		scanf("%d", &s);
		
		// check the condtions and output the result 
		// If there is one unique order giving the specified total cost, output a space-separated list of the numbers of the items on that order in ascending order.
		// If the order contains more than one of the same item, print the corresponding number the appropriate number of times.
		// If there doesn’t exist an order that gives the specified sum, output Impossible.
		// If there are more than one order that gives the specified sum, output Ambiguous.
		int output = checkOrders(0, s);
		if(output == 0){
			printf("Impossible\n");
		}
		else if(output == 1){
			counter = 0;
			printOutput(0, s);
			printf("\n");
		}
		else
			printf("Ambiguous\n");
	}
}