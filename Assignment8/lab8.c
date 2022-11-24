#include <stdio.h>
#include <math.h>

// COMPILE WITH -lm !!!
void printTSO(int blockSizeInBytes, int numSets, int archSizeInBits) {
        int setBits = 0;
        if (numSets > 1) {
                setBits = log2(numSets);
        }
        int offsetBits = log2(blockSizeInBytes);
        int tagBits = archSizeInBits - setBits - offsetBits;
        printf("%dB blocks, %d sets, %d-bit architecture: %d tag bits, %d set bits, %d offset bits.\n",
                        blockSizeInBytes, numSets, archSizeInBits, tagBits, setBits, offsetBits);
}


// 256B blocks, 1 sets, 32-bit architecture: 24 tag bits, 0 set bits, 8 offset bits.
// What this means:
// For some address 0x12345678
// Grab Bytes 0x12345600 through 0x123456FF into cache
// Then read from cache w/ offset, like a pointer into the cacheA
//
// Block size of 2 bytes
// Splits RAM unto pairs of bytes, one pair read to cache at a time
// e.g. 0x12345678 would read 0x12345678 and 0x12345679 into cache
// access cache by 0 or 1 (LSB of 8 or 9)


// LAB 8: 256B block, 1 set, 32 bit arch
// <tag><set><offset>
unsigned int getOffset(unsigned int address) {
	unsigned int mask = 0x000000FF;
	unsigned int offset = address & mask;
	return offset;
}

unsigned int getTag(unsigned int address) {
	unsigned int mask = 0xFFFFFF00;
	unsigned int tag = address & mask;
	tag >>= 8;
	return tag;
}

void main() {
        printTSO(256, 1, 32);
        unsigned int testAddr1 = 0x12345678;
        unsigned int testAddr2 = 0x87654321;
        // uncomment after implementing
        printf("0x%08x: offset - %x, tag - %x.\n", testAddr1, getOffset(testAddr1), getTag(testAddr1));
        printf("0x%08x: offset - %x, tag - %x.\n", testAddr2, getOffset(testAddr2), getTag(testAddr2));
}
