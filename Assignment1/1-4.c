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

void printLongLong(long long x){
	printBytes((unsigned char *) &x, sizeof(long long));
}

void printDouble(double x){
	printBytes((unsigned char *) &x, sizeof(double));
}

int main(){
	printInt(-53);
	printFloat(15.5);
	printShort(13);
	printLong(24L);
	printLongLong(9223372031853775807);
	printDouble(3.14159);
}
