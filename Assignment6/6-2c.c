#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inner(float *u, float *v, int length, float *dest) {
	int i;
	float sum = 0.0f;
	for (i = 0; i < length; ++i) {
		sum += u[i] * v[i];
	}
	*dest = sum;
}

void inner2(float *u, float *v, int length, float *dest) {
	int i;
	int limit = length - 3;
	float sum = 0.0f;
	for (i = 0; i < limit; i+=4) {
		sum += u[i] * v[i];
		sum += u[i+1] * v[i+1];
		sum += u[i+2] * v[i+2];
		sum += u[i+3] * v[i+3];
	}

	for(i; i < length; i++){
		sum += u[i] * v[i];
	}
	*dest = sum;
}

int main(){
	float arr1[4] = {1, 2, 3, 4};
	float arr2[4] = {5, 6, 7, 8};
	float x, y;
	int len = 4;
	inner(arr1, arr2, len, &x);
	inner2(arr1, arr2, len, &y);
	printf("x = %f\n", x);
	printf("y = %f\n", y);
}
