/*
COMP321 A1 Problem 3: I Can Guess the Data Structure
Author: Simon Hsu
Date: Jan 30, 2017
*/
#include<stdio.h>
int op[1000], x[1000];
int testStack(int n) {
	int s[1000], index = -1, i;
	for(i = 0; i < n; i++) {
		if(op[i] == 1) {
			//push
			s[++index] = x[i];
		}
		else {
			if(index < 0 || s[index] != x[i]){
				return 0;
			}
			--index;
		}
	}
	return 1;
}
int testQ(int n) {
	int q[1000], h = 0, t = -1, i;
	for(i = 0; i < n; i++) {
		if(op[i] == 1){
			//push
			q[++t] = x[i];
		}
		else {
			if(h > t || q[h] != x[i]){
				return 0;
			}
			++h;
		}
	}
	return 1;
}
int testPQ(int n) {
	int h[1000], largest = 0, parent, s, temp, i;
	for(i = 0; i < n; i++) {
		if(op[i] == 1) {
			h[++largest] = x[i];
			s = largest, parent = s>>1;
			while(s >= 2 && h[s] > h[parent]) {
				temp = h[s], h[s] = h[parent], h[parent] = temp;
				s = parent, parent = s>>1;
			}
		} else {
			if(largest < 1 || h[1] != x[i]){
				return 0;
			}
			temp = h[largest], h[largest] = h[1], h[1] = temp;
			parent = 1, s = parent<<1, --largest;
			while(s <= largest) {
				if(s < largest && h[s+1] > h[s]){
					s++;
				}
				if(h[s] <= h[parent]){
					break;
				}
				temp = h[s], h[s] = h[parent], h[parent] = temp;
				parent = s, s = parent<<1;
			}
		}
	}
	return 1;
}
int main(){
	int n, i;
	int nmax = 1000;
	int nmin = 1;
	int xmax = 100;
	int xmin = 0;
	
	//scan to see how many commands you are going to have
	while(scanf("%d", &n) == 1){
		if((nmin <=n) && (n <= nmax)){
			for(i = 0; i < n; i++){
				scanf("%d %d", &op[i], &x[i]);
			}
			if((xmin <= x[i]) && (x[i] <= xmax)){
				//two operations: put x in the bag, take x out of the bag
			}
			else{
				printf("x is not in the range of 0 to 100");
				break;
			}
		}
		else{
			printf("n is not in the range of 1 to 1000!\n");
		}
			int number = 0;
			int solution;
			//check which data structure it is in here
			if( testStack(n) ){
				solution = 1, number++;
			}
			if( testQ(n) ){
				solution = 2, number++;
			}
			if( testPQ(n) ){
				solution = 3, number++;
			}
			//when it can't be a s, a q or a priority q, print impossible
			if(number == 0){
				printf("impossible\n");
			}
			else if(number == 1) {
				//when it’s definitely a s, print s
				if(solution == 1){
					printf("stack\n");
				}
				//when it's definitely a q, print q
				else if(solution == 2){
					printf("queue\n");
				}
				//when it's definitely a priority q, print priority q
				else{
					printf("priority queue\n");
				}
			}
			//when it can be more than one of the three data structures mentioned above
			else {
				printf("not sure\n");
			}
		
	}
		
	return 0;
}

