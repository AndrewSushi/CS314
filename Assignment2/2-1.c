#include <stdio.h>

int mask(int n){
	int mask1 = 1;
	return (mask1 << n) - 1;
}

int main(){
	printf("0x%x == 0x1\n", mask(1));
	printf("0x%x == 0x3\n", mask(2));
	printf("0x%x == 0x7\n", mask(3));
	printf("0x%x == 0x1F\n", mask(5));
	printf("0x%x == 0xFF\n", mask(8));
	printf("0x%x == 0xFFFF\n", mask(16));
	printf("0x%x == 0x7FFFFFFF\n", mask(31));

	return 0;
}
