#include <stdio.h>
#include <stdlib.h>

unsigned int getOffset(unsigned int address){
	unsigned int mask = 0x000000FF;
	unsigned int offset = address & mask;
	return offset;
}

unsigned int getSet(unsigned int address){
	unsigned int mask = 0x00000F00;
	unsigned int set = address & mask;
	return set >> 8;
}

unsigned int getTag(unsigned int address){
	unsigned int mask = 0xFFFFFF00;
	unsigned int tag = address & mask;
	tag >>= 8;
	return tag >> 4;
}

int main(){
	printf("0x12345678: offset: %x = tag: %x - set: %x\n", getOffset(0x12345678), getTag(0x12345678), getSet(0x12345678));
	printf("0x87654321: offset: %x = tag: %x - set: %x\n", getOffset(0x87654321), getTag(0x87654321), getSet(0x87654321));
}
