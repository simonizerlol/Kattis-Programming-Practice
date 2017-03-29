/*
COMP321 A1 Problem 1: The Easiest Problem Is This One
Author: Simon Hsu
Date: Jan 30, 2017
*/
#include <stdio.h>
#include <stdlib.h>

//compute the sum of n
int sumOfNumber(int s){
	int tmp = s;
	int digit;
	int sum = 0;
	while(tmp > 0){
		digit = tmp % 10;
		sum = sum + digit;
		tmp /= 10;
	}
	return sum;
}

int main() {
	int n;
    	int nmin = 1;
	int nmax = 100000;
	int m;
	int output[1000];
	scanf("%d", &n);
	//keep on scanning and store the integer unless it's an 0

	while(n != 0){
		m = n;
		if((nmin <= m) && (m <= nmax)){
			//compute the sum of n and store in sumArr
			int sumN = sumOfNumber(m);
			int p = 11;
			int output[100];
			int compare = 0;
			int i = 0;
			while (compare != 1){
				int mp = m * p;
				int sumMP = sumOfNumber(mp);
				if (sumN == sumMP){
					printf("%d\n", p);
					compare = 1;
				}
				else{
					p++;
				}
			}
		scanf("%d", &n);
	}
		else{
			printf("n is not in the range of 1 to 100000!");
			break;
		}
	}
	return 0;
}

