#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float f(float *a, int n) {
	float prod = 1.0f;
	for (int i = 0; i < n; ++i) {
		if (a[i] != 0.0f) {
			prod *= a[i];
		}
	}
	return prod;
}

float g(float *b, int n){
	float prod = 1.0f;
	for (int i = 0; i < n; ++i) {
		prod *= b[i];
	}
	return prod;
}

float* createArray(int size) {
	float *a = (float *)malloc(size * sizeof(float));
	for (int i = 0; i < size; ++i) {
		// 50% chance that a[i] is 0.0f, random value on the range
		// [0.76, 1.26] otherwise.
		float r = rand()/(float)RAND_MAX;
		a[i] = r < 0.5f ? 0.0f : r + 0.26f;
	}
	return a;
}

int main(){
	float *a = createArray(10000);
	clock_t start = clock();
	float fa = f(a, 10000);
	clock_t end = clock();
	double a_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("F(a): %lf, Time: %lf\n", fa, a_time); // Time: 0.000107
	
	float *b = (float *)malloc(sizeof(float) * 10000);
	for(int i = 0; i < 10000; i++){
		if(a[i] == 0){
			b[i] = 1.0f;
		}else{
			b[i] = a[i];
		}
	}
	start = clock();
	float gb = g(b, 10000);
	end = clock();
	double b_time = ((double) (end - start)) / CLOCKS_PER_SEC;	
	printf("G(b): %lf, Time: %lf\n", gb, b_time); // Time: 0.000026
	// G(b) is faster since you don't have to check for a conditional each iteration and there are array lookups in the conditional;
	int n = 0;
	for(int i = 0; i < 10000; i++){
		if(a[i] != 0){
			n++;
		}
	}
	float *c = (float *)malloc(sizeof(float) * n);
	int idx = 0;
	for(int i = 0; i < 10000; i++){
		if(a[i] != 0){
			c[idx] = a[i];
			idx++;
		}
	}
	start = clock();
	float gc = g(c, n);
	end = clock();
	double c_time = ((double) (end - start)) / CLOCKS_PER_SEC;	
	printf("G(c): %lf, Time: %lf\n", gc, c_time); // Time: 0.000013
	// Since we do not have check if 0, since there are no 0 elements so there are less elements which equals less operations done.
	free(a);
	free(b);
	free(c);
}
