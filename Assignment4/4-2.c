#include <stdio.h>

long fact(long x){  // %rbx is the stack pointer
					// pushq %rbx pushes the value onto the stack as well as the memory address
					// movq %rdi, %rbx changes the value of %rbx to the value of %rdi which is passed in as x
	if(x <= 1){ // %rdi is x	// cmpq $1, %rdi jumps if %rdi is <= 1. This is the base case for the recusion to stop
		return 1;		// movl $1, %eax makes the return value 1 so that everything can start multiplying
	}
	return x * fact(x - 1); // leaq statement moves %rdi - 1 into %rdi which then is called recursively
							// every imulq multiplies return (%rax) by %rbx, where %rbx is %rdi in the current iteration, which is stored in %rbx
							// popq %rbx pops the value at the bottom of the stack 							
// At the base case of recursion, we have pushed all incrementations into rbx, where then each element is popped after getting multiplied
// The stack size is ((x-1) * 2) * 8 because the stack frame only gets created once another function is called within the function
}

int main(){
	printf("fact(%ld): %ld\n", 1, fact(1));
	printf("fact(%ld): %ld\n", 3, fact(3));
	printf("fact(%ld): %ld\n", 5, fact(5));
}
