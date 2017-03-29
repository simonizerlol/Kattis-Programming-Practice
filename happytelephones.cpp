// COMP 321 A5 Q1 Happy Telephones
// Name: Simon Hsu
// ID: 260610820
// Date: 2017.03.07
#include <cstdio> // c++ version of stdio.h
#include <algorithm> // std::max and std::min 

using namespace std;

int main(){
	// N = the number of phone calls
	// M = the number of intervals
	// s = source
	// d = destination
	// start = start time (within 10000 seconds)
	// duration = duration time (within 10000 seconds)
	int N, M, s, d, a, b;
	int start[10000], duration[10000]; 
	int i, j, counter;
	
	scanf("%d %d", &N, &M);
	
	while((N != 0) & (M != 0)){
		// there are N phone calls
		// each phone calls consists 4 integers, s, d, start, and duration.
		for(i = 0; i < N; i++){
			scanf("%d %d %d %d", &s, &d, &start[i], &duration[i]);
		
			duration[i] += start[i];
		}
		
		// for the M intervals that police are interested in,
		// each interval consists 2 integers, s and d
		for(i = 0; i < M; i++){
			counter = 0;
			scanf("%d %d", &s, &d);

			// check if the given interval range is overlapping with the other call duration.
			for(j = 0; j < N; j++){
				// max(a, b) returns the largest of a and b. If both are equivalent, a is returned.
				// min(a, b) returns the smallest of a and b. If both are equivalent, a is returned.
 				a = max(s, start[j]);
				b = min(s + d, duration[j]);
				if(b - a > 0){
					counter++;
				} 
			}
			printf("%d\n", counter); // output the number of calls that are active during at least one second of the interval.
		}
		scanf("%d %d", &N, &M);
	}
	return 0; // end of program
}