#include <stdio.h>

unsigned int replace(unsigned int x, int i, unsigned char b){
	unsigned int mask = (b << (i<<3)); 		// Creating a mask with char b and inserting it into the correct location
	unsigned int mask2 = (0xff << (i<<3)); 	// Creating a second mask to remove the bits from x
	x &= ~mask2; 							// Masking x with the negation of the second mask
	return x |= mask;						// Inserting in the original mask back into x
}

int main(){
	printf("0x%x == 0xAB345678\n", replace(0x12345678, 3, 0xAB));
	printf("0x%x == 0x123456AB\n", replace(0x12345678, 0, 0xAB));

	return 0;
}

