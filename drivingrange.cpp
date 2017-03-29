#include <stdio.h>
#include <stdlib.h>
int main(){
	int n, m;
	
	scanf("%d %d", &n, &m);
	//printf("%d %d\n", n, m);
	if(n == 0 || m==0){
		printf("IMPOSSIBLE\n");
	}
	return 0;
}