/*
COMP321 A1 Problem 2: Oddities
Author: Simon Hsu
Date: Jan 30, 2017
*/
#include<stdio.h>
#include<stdlib.h>

int main(){
	//variables declaration
	int n, i, inputArr[30];
	int nmin = 1;
	int nmax = 20;
	int xmin = -10;
	int xmax = 10;
	//scan number of inputs
	scanf("%d", &n);

	if((nmin <= n) && (n <= nmax)){
		//scan the inputs and store in inputArray
		for(i=0; i < n; i++){
		   scanf("%d", &inputArr[i]);
		   if((xmin <= inputArr[i]) && (inputArr[i] <= xmax)){

		   }
		   else{
			   printf("x is not in the range of -10 ~ 10!!");
			   break;
		   }
		}

		//check odd or even
		for(i=0; i < n; i++){
				if (inputArr[i]%2 == 0){
					printf("%d is even\n", inputArr[i]);
				}
				else {
					printf("%d is odd\n", inputArr[i]);
				}
			}
		}
		else {
			printf("not an valid input, please input from 1 to 20!\n");
		}
	return 0;
	}




