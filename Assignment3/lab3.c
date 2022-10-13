// convert 11100101 from 8 bit float to decimal

// 1 110 0101

// separate sign, exponent, and mantissa

// sign = 1; exponent = 110, mantissa = 0101
// restore the mantissa leading 1
// 1.0101

// subtract bias from exponent. bias = 2^(k-1)-1, where k = number of digits in exponent field (3 for 8bit floats)

// k = 3, 2^(3-1)-1 = 2^2 - 1 = 4 - 1 = 3 = bias
// exp is 110 in binary so it's 6 in base 10
// so exp - bias = 6 - 3 = 3

// denormalize mantissa: move decimal point according to the preceeding step

// 1.0101 * 2^(3) = 1010.1

// convert to decimal: multiply each digit by 2^x, where x is the "place" of the digit, and then sum
// 2^(3) 2^(2) 2^(1) 2^(0) 2^(-1)
// 1     0     1     0     1
// 8     0     2     0     0.5
// sum: 8 + 2 + 0.5 = 10.5

// apply sign bit
// -10.5

#include <stdio.h>

unsigned int unsignedBinaryToDecimal(unsigned char *s, int length) {
    unsigned int result = 0;
    for (int i = 0; i < length; i++) {
    	unsigned int exp = 1 << i;
		unsigned int bit = s[length - 1 - i];
		unsigned int mult = bit * exp;
		result += mult;
		printf("Step %d: %d * %d.\n", i, bit, exp);
	}
    return result;
}

int main() {
    unsigned char s[4] = {1, 0, 1, 1};

    printf("%d\n", unsignedBinaryToDecimal(s, 4));
}
