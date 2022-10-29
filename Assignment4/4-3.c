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

void print_data(array_t a){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void transposeOpt(array_t a){
	for(long i = 0; i < N; ++i){
		long *row_pointer = &a[i][0];
		long *col_pointer = &a[0][i];
		for(long j = 0; j < i; ++j){
			long t1 = *row_pointer;
			long t2 = *col_pointer;
			*row_pointer = t2;
			*col_pointer = t1;
			row_pointer++;
			col_pointer += N;
		}
	}
}

// .L3: for(long i = 0; i < N ; ++i)
// movq (%rax), %rcx Move memory address at a[i][j] to t1
// movq (%rdx), %rsi Move memory address at a[j][i] to t2
// movq %rsi, (%rax) Replace value stored in a[j][i] to the value that t2 points to
// movq %rcx, (%rdx) Replace value stored in a[i][j] to the value that t1 points to
// addq $8, %rax Increment the row_pointer by 8 bytes which is the next value in the row array and it is 8 because it is an array of longs
// addq $32, %rdx Increment the col_pointer by 32 bytes which is the next value in the column and it is 32 sign it is N * 8
// cmpq %r9, %rax Conditional for the for loop checking if j < i
// jne .L3 If the conditional is not equal, jump to .L3, which is the start of the loop

int main(){
	array_t a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	transposeOpt(a);
	print_data(a);
	return 0;
}
