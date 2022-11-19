#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float *createArray(float *arr, int len){
	for(int i = 0; i < len; i++){
		arr[i] = rand() % 5;
	}
	return arr;
}

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
//	for(int i = 1000000; i <= 10000000; i +=1000000){
	int len = 10000000;
	float *arr1 = (float *)malloc(sizeof(float) * len);
	float *arr2 = (float *)malloc(sizeof(float) * len);
	float x, y;
	arr1 = createArray(arr1, len);
	arr2 = createArray(arr2, len);
	clock_t start = clock();
	inner(arr1, arr2, len, &x);
	clock_t end = clock();
	double totalTime1 = ((double) (end - start)) / CLOCKS_PER_SEC;

	start = clock();
	inner2(arr1, arr2, len, &y);
	end = clock();
	double totalTime2 = ((double) (end - start)) / CLOCKS_PER_SEC;
//	printf("Elements: %d, Iteration: %d\n", i, i/1000000);
	printf("x = %f, time = %lf\n", x, totalTime1);
	printf("y = %f, time = %lf\n", y, totalTime2);
	printf("\n");
}
//}
