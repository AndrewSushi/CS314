#include <stdio.h>
#include <stdlib.h>

struct IntArray{
	int length;
	int *dataPtr;
};

struct IntArray* mallocIntArray(int length){
	struct IntArray *arr = (struct IntArray *)malloc(sizeof(struct IntArray));
	arr->dataPtr = (int *)malloc(sizeof(int) * length);
	return arr;
}

void freeIntArray(struct IntArray *arrayPtr){
	free(arrayPtr->dataPtr);
	free(arrayPtr);
}

void readIntArray(struct IntArray *array){
	char arr[array->length];
	for(int i = 0; i < array->length; i++){
		while(1){
			fgets(arr, sizeof(arr), stdin);
		}
	}
}

int main(){
	
}
