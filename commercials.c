// COMP 321 A3 Q3 radio commercial
// Name: Simon Hsu
// ID: 260610820
// Date: 2017.02.11
#include<stdio.h>
// there are no min and max defined in C, need to write one.
#define max(x, y) ({ __typeof__ (x) _x = (x); __typeof__ (y) _y = (y); _x > _y ? _x : _y; })
// the macro works but it could cause problem
// #define max(x, y) (((x) > (y)) ? (x) : (y))
int main() {
	int N, P, array[100000];
	scanf("%d %d\n", &N, &P);
	for (int i = 0; i < N; i++) {
		scanf("%d", &array[i]);
	}

	int x, maxI;
	x = maxI = 0;

	// find maximum sum of subarray (linear time)
	// go through the whole array once
	for (int i = 0; i < N; i++) {
		x = max(0, x + array[i] - P);
		maxI = max(x, maxI);
	}

	printf("%d\n", maxI);
}