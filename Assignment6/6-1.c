#include <stdio.h>
#include <stdlib.h>

int f(int a, int b, int c, int d, int n) {
	int result = 0;
	int axb = a * b;
	int cxd = c * d;
	int temp = 0;
	for(int i = 0; i < n; ++i){
		if(i){
			temp += cxd;
		}
		for(int j = 0; j < n; ++j){
			result += axb + temp + j;
		}
	}
	return result;
}

int main(){
	printf("%d\n", f(1, 2, 3, 4, 5));// 700
	printf("%d\n", f(2, 3, 4, 5, 6));// 2106
	printf("%d\n", f(6, 5, 4, 3, 2));// 146
	printf("%d\n", f(5, 4, 3, 2, 1));// 20
}
