// COMP 321 A3 Q2 Closest Sums
// name: Simon Hsu
// ID: 260610820
// Date: 2017.02.11
#include<stdio.h>
#include <stdlib.h>

int main(){
    int n, m, caseNumber = 1;
	int array[1000]; // each case starts wth an integer 1 < n <= 1000
    int ClosestSum, currentCS, input;
	
	// the loop continues if input is integer
    while(scanf("%d", &n) == 1){
		// first thing to print is the case number:
        printf("Case %d:\n", caseNumber++);
		
		// scan the integer numbers, loops stops after n integers.
        for(int i = 0; i < n; i++ )
            scanf("%d", &array[i]);

        scanf("%d", &m); // scan for the number of queries.
		
		// while m is true, it decrements and compute closest sum for the input integers in the query.
        while(m--){
			scanf("%d", &input);
			// compute closest sum
			ClosestSum = array[0] + array[1];
			for(int i = 0; i < n; i++){
				for(int j = i+1; j < n; j++){
					currentCS = array[i] + array[j];
					// abs(x) returns the absolute value of x
					if(abs(ClosestSum - input) > abs(currentCS - input)){
						ClosestSum = currentCS;
					}
				}
			}
			printf("Closest sum to %d is %d.\n", input, ClosestSum);
        }
    }
    return 0;
}