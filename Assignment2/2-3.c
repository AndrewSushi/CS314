#include <stdio.h>

int le(float x, float y){
	unsigned int ux = *((unsigned int*) &x); // Convert x raw bits
	unsigned int uy = *((unsigned int*) &y); // Convert y raw bits
	unsigned int sx = ux >> 31; // Extract sign but of ux
	unsigned int sy = uy >> 31; // Extract sign bit of uy
	ux <<= 1; // drop sign bit of ux
	uy <<= 1; // drop sign bit of uy

	int cond1 = ((sx > sy) && (ux > uy));
	int cond2 = (sx >= sy) && (ux == uy);
	int cond3 = ((sx || sy) == 0) && (ux <= uy);
	return cond1 || cond2 || cond3;
}

int main(){
	printf("%d == 1\n", le(0.0f, 0.0f));
	printf("%d == 1\n", le(-0.0f, 0.0f));
	printf("%d == 1\n", le(-1.0f, -1.0f));
	printf("%d == 1\n", le(1.0f, 1.0f));
	printf("%d == 1\n", le(-1.0f, 0.0f));
	printf("%d == 1\n", le(0.0f, 1.0f));
	printf("%d == 0\n", le(1.0f, 0.0f));
	printf("%d == 0\n", le(0.0f, -1.0f));
	printf("%d == 0\n", le(-1.0f, -2.0f));
}
