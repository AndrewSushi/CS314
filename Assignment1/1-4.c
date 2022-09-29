#include <stdio.h>

void printBytes(unsigned char *start, int len){
	for(int i = 0; i < len; ++i){
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

void printInt(int x){
	printBytes((unsigned char *) &x, sizeof(int));
}

void printFloat(float x){
	printBytes((unsigned char *) &x, sizeof(float));
}

void printShort(short x){
	printBytes((unsigned char *) &x, sizeof(short));
}

void printLong(long x){
	printBytes((unsigned char *) &x, sizeof(long));
}

void printDouble(double x){
	printBytes((unsigned char *) &x, sizeof(double));
}

int main(){
	printInt(-53);
	printFloat(10.5);
	printShort(13);
	printLong(24L);
	printDouble(3.14159);
}
