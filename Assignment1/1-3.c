#include <stdio.h>

int oddBit(unsigned int x){
	unsigned int mask = 0xAAAAAAAA; // Create a mask of 101010... that is 32 bits long
	x &= mask; // And the x value and the mask together, if the value of x is greater than 0, then there is a 1 at an odd index, 
               	   //if not then there is none
	return x && x; // If true, reduce the number to 1 (true) by logical AND with itself, otherwise 0 And 0 will result 0
}

int main(){
	printf("%d == 0\n", oddBit(0x1));
	printf("%d == 1\n", oddBit(0x2));
	printf("%d == 1\n", oddBit(0x3));
	printf("%d == 0\n", oddBit(0x4));
	printf("%d == 1\n", oddBit(0xFFFFFFFF));
	printf("%d == 1\n", oddBit(0xAAAAAAAA));
	printf("%d == 0\n", oddBit(0x55555555));
	return 0;
}
