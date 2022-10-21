#include <stdio.h>

long f(long x, long y, long z){
	z += y;
	x *= z;
	z = z << 63;
	z = z >> 63;
	int w = x;
	w = x ^ w;
	return x;
}

int main(){
	printf("%d\n", f(1, 2, 4));
	printf("%d\n", f(3, 5, 7));
	printf("%d\n", f(10, 20, 30));
}
