#include <stdio.h>
#include <stdlib.h>

/*
long sum(long from, long to){
	long result = 0;
	loop:
		result += from;
		++from;
	if(from <= to) goto loop;
	return result;
}
*/

int main(){
	printf("sum(1, 6): %ld\n", sum(1, 6));
	printf("sum(3, 5): %ld\n", sum(3, 5));
	printf("sum(5, 3): %ld\n", sum(5, 3));
	return 0;
}
