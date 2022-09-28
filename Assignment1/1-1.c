#include <stdio.h>

int combine(int x, int y){
	y = y & 0xff; //Masking the int y and retriving the last byte
	x = x & 0xffffff00; //Masking the int x and retriving the signifact bytes 1-3
	return x | y;
}

int main(){
	printf("0x%x == 0x12345600\n", combine(0x12345678, 0xABCDEF00));
	printf("0x%x == 0xABCDEF78\n", combine(0xABCDEF00, 0x12345678));
}
