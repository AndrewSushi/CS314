#include <stdio.h>

int extract(unsigned int x, int i){
	signed int x1 = 0xFFFFFFFF;
	int mask = x & (0xFF<<(i<<3));
	char x2 = mask >> ((i) << 3);
	return x1 & x2;
}

int main(){
	printf("0x%x == 0x00000078\n", extract(0x12345678, 0));
	printf("0x%x == 0xFFFFFFCD\n", extract(0xABCDEF00, 2));

	return 0;
}
