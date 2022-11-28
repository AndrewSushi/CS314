#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2048

struct ColorPoint {
	long a;
	long r;
	long g;
	long b;
};

long f(struct ColorPoint **points, int n) {
	long sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += points[j][i].a;
			sum += points[j][i].r;
			sum += points[j][i].g;
			sum += points[j][i].b;
		}
	}
	return sum;
}

long g(struct ColorPoint **points, int n) {
	long sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += points[i][j].a;
			sum += points[i][j].r;
			sum += points[i][j].g;
			sum += points[i][j].b;
		}
	}
return sum;
}

struct ColorPoint** create2DArray(int n) {
	// Array to hold a pointer to the beginning of each row
	struct ColorPoint **points = (struct ColorPoint **)malloc(n * sizeof(struct ColorPoint *));
	for (int i = 0; i < n; ++i) {
		// Array to hold each row
		points[i] = (struct ColorPoint *)malloc(n * sizeof(struct ColorPoint));
		for (int j = 0; j < n; ++j) {
			// Init the ColorPoint struct
			points[i][j].a = rand();
			points[i][j].r = rand();
			points[i][j].g = rand();
			points[i][j].b = rand();
		}
	}
	return points;
}

void free2DArray(struct ColorPoint** points, int n) {
	for (int i = 0; i < n; ++i) {
		free(points[i]);
	}
	free(points);
}

int main(){
	struct ColorPoint **cpf = create2DArray(N);
	struct ColorPoint **cpg = create2DArray(N);
	
	clock_t start = clock();
	f(cpf, N);
	clock_t end = clock();
	double totalTime1 = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("F: %f\n", totalTime1); // 0.069979 average of 5 runs
	free2DArray(cpf, N);

	start = clock();
	g(cpg, N);
	end = clock();
	double totalTime2 = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("G: %f\n", totalTime2); // 0.025896 average of 5 runs
	free2DArray(cpg, N);

	// I believe that f() takes longer since you have to cache each struct where as with g() you only have to cache once every two structs. This is because f() uses [j][i] which makes it cache each iteration whereas f() uses [i][j] which causes it to cache once every two structs.
}
