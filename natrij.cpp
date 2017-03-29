#include <stdio.h>
#include <stdlib.h>
// created by Simon Hsu for COMP321 contest 0 and assignment 7
// Date: 2017.03.22
int main(){
	int h,m,s;
	int bh, bm, bs;
	int sh, sm, ss;
	scanf("%d:%d:%d\n", &h, &m, &s);
	scanf("%d:%d:%d", &bh, &bm, &bs);

	ss = bs - s;
	sm = bm - m;
	sh = bh - h;
	
	if(ss < 0){
		ss += 60;
		sm -= 1;
	}
	if(sm < 0){
		sm += 60;
		sh -= 1;
	}
	if(sh < 0){
		sh += 24;
	}
	
	if(sh + sm + ss == 0){
		sh += 24;
	}
	printf("%02d:%02d:%02d\n", sh,sm,ss);
}