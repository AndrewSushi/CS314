#import <stdio.h>
#define UI unsigned int

unsigned char getByte(UI x, int i) {
    // TODO: implement
	UI shift = i << 3; // Multiplying by 8 to shift
	UI mask = 0xFF << shift; // Creating the mask and shifting it
	return (x & mask) >> shift;
	
}

UI swap(UI x, int a, int b) {

    UI aVal = getByte(x, a); // isolate byte a of x
    UI bVal = getByte(x, b); // isolate byte b of x
    UI aShift = a << 3; // multiply by 8
    UI bShift = b << 3; // multiply by 8
    UI aMask = 0xFF << aShift; // shift 0xFF left by 8*a
    UI bMask = 0xFF << bShift; // shift 0xFF left by 8*b
    x &= ~aMask; // invert mask (e.g., 0x000000FF -> 0xFFFFFF00) to clear space for the bVal
    x &= ~bMask; // invert mask (e.g., 0x000000FF -> 0xFFFFFF00) to clear space for the aVal
    x |= bVal << aShift; // align bVal, combine with x
    x |= aVal << bShift; // align aVal, combine with x
    return x;
}

int main() {
    UI test = 0xABCDEF12;
    for (int i = 0; i < 3; i++) {
        printf("swap(0x%08X, 3, %d): 0x%08X.\n", 
        test, i, swap(test, 3, i));
    }
}
