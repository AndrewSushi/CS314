#include <stdio.h>

int extract(unsigned int x, int i){
	int mask = (0xFF << (i<<3)) & x;
	mask >>= (i<<3);
	int ext = x >> 31;
	int mask2 = 0 - ext;
	mask2 = mask2 & 0xFFFFFF00;
	return mask | mask2;
}

int main(){
	printf("0x%x == 0x00000078\n", extract(0x12345678, 0));
	printf("0x%x == 0xFFFFFFCD\n", extract(0xABCDEF00, 2));
	printf("0x%x == 0xFFFFFF12\n", extract(0xFB12EF00, 2));
	printf("0x%x == 0x00000056\n", extract(0x12345678, 1));
	printf("0x%x == 0x00000034\n", extract(0x12345678, 3));
	return 0;
}
