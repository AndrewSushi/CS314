#include <stdio.h>

// original C function:
//
// int sumArr(long *a, long size) {
//   long result = 0;
//   for (long i = size - 1; i >= 0; --i) {
//     result += a[i];
//   }
//   return result;
// }
//
// assembly: your implementation below

long sumArr(long *a, long size) {
        // Declare and initialize result var – do not modify.
        long result = 0;

        // Ensure that argument *from* is in %rdi,
        // argument *to* is in %rsi, *result* is in %rax - *do
        // not modify*.
        __asm__ ("movq %0, %%rdi # from in rdi;" :: "r" ( a ));
        __asm__ ("movq %0, %%rsi # to in rsi;" :: "r" ( size ));
        __asm__ ("movq %0, %%rax # result in rax;" :: "r" ( result ));

        // Your x86-64 code goes below - comment each instruction...
        __asm__(
                // TODO - Replace the two lines below with add, compare,
                // jump instructions, labels, etc as necessary to implement
                // the loop.
		// comment each line explaining its purpose

                "subq $1, %rsi;" // long i = size - 1
                ".LOOP:"
                "cmpq $-1, %rsi;" // i == -1, effectivbely doing i >= 0
                "je .END;" // jumps to .END if previous flag set to the equal flag (ZF)
                "addq (%rdi, %rsi, 8), %rax;" // result += a[i]
				// rax += rdi + 8*rsi
                "subq $1, %rsi;" // Decrement the for loop variable
                "jmp .LOOP;" // Unconditional jump to .LOOP
                ".END:"
        );

        // Ensure that *result* is in %rax for return - *do not modify*.
        __asm__ ("movq %%rax, %0 #result in rax;" : "=r" ( result ));
        return result;
}

int main() {
        long testArr[5] = {1, 2, 3, 4, 5};
        printf("sumArr({1, 2, 3, 4, 5}, 5): %ld\n", sumArr(testArr, 5));
}
