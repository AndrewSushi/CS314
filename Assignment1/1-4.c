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
	printInt(53); // There are 4 groups of characters and the last 3 are all 0's, meaning that it is little endian, also that it is 32 bit
	printFloat(1.0); // There are again 4 groups but the rest of the digits are stored after the integer
	printShort(9876); // There are 2 groups, meaning that it is 16 bits
	printLong(242349823); // There are 8 groups meaning that it is 64 bits
	printLongLong(9223372031853775807); // There are also 8 groups
	printDouble(3.14159); // The double has the same memory allocation as a long but is used for decimals that are more precise. 
}
