// COMP 321 A5 Q3 A Vicious Pikeman (Easy)
// Name: Simon Hsu
// ID: 260610820
// Date: 2017.03.07
#include <stdio.h>  
#include <stdlib.h>  
#include <stdint.h>  

#define penaltyModulo 1000000007

int compareFunction(const void *a,const void *b){
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}

int main(void){
	// N = number of problems 
	// T = contest time 
	// initialize the inputs
    unsigned long long N, T, A, B, C, t;
    unsigned long long penalty = 0;
    unsigned long long timeSpent = 0;
    unsigned long long maxNumberProblemCanSolve = 0;
	int i;
	
    scanf("%llu %llu", &N, &T);
    scanf("%llu %llu %llu %llu", &A, &B, &C, &t);
    
	unsigned long long timeRequiredforProblem[N];
	// t = t0, the time required for solving the first problem
    timeRequiredforProblem[0] = t;
	
	// compute ti
    for(i = 1; i < N; i++){
        t = (((A * t) + B) % C) + 1;
        timeRequiredforProblem[i] = t;
    }
	// sort N elements of the array pointed to by timeRequiredforProblem
	// each element size bytes long, using compare fuction to determine the order
    qsort(timeRequiredforProblem, N, sizeof(unsigned long long), compareFunction);
    
	// compute the maximum number of problems can solve within the limit T
    for(i = 0; i < N; i++){
        if(timeSpent + timeRequiredforProblem[i] <= T){
            penalty = (penalty + timeRequiredforProblem[i] + timeSpent) % penaltyModulo;
            timeSpent += timeRequiredforProblem[i];
            maxNumberProblemCanSolve++;
        } 
		else{
            break;
        }
    }
    printf("%llu %llu\n", maxNumberProblemCanSolve, penalty);
}