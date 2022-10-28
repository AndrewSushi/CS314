#include <stdio.h>

#define N 4
typedef long array_t[N][N];

/*
void transpose(array_t a) {
    for (long i = 0; i < N; ++i) {
        for (long j = 0; j < i; ++j) {
            long t1 = a[i][j];
            long t2 = a[j][i];
            a[i][j] = t2;
            a[j][i] = t1;
        }
    }
}
*/

void transpose(array_t a){
	for(long i = 0; i < N; ++i){
		for(long j = 0; j < i; ++j){
			
		}
	}
}

// .L3: for(long i = 0; i < N ; ++i)
// movq (%rax), %rcx 
// movq (%rdx), %rsi
// movq %rsi, (%rax)
// movq %rcx, (%rdx)
// addq $8, %rax
// addq $32, %rdx
// cmpq %r9, %rax
// jne .L3

int main(){
	array_t a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15,
16}};
	return 0;
}
