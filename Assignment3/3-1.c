#include <stdio.h>
#include <stdlib.h>

struct IntArray{
	int length;
	int *dataPtr;
};

struct IntArray* mallocIntArray(int length){
	struct IntArray *arr = (struct IntArray *)malloc(sizeof(struct IntArray));
	arr->dataPtr = (int *)malloc(sizeof(int) * length);
	arr->length = length;
	return arr;
}

void freeIntArray(struct IntArray *arrayPtr){
	free(arrayPtr->dataPtr);
	free(arrayPtr);
}

void readIntArray(struct IntArray *array){
	char lineBuf[10];
	char *p = NULL;
	int n;
	for(int i = 0; i < array->length; i++){
		while(1){
			printf("Enter int: ");
			fgets(lineBuf, sizeof(lineBuf), stdin);
			n = strtol(lineBuf, &p, 10);
			if(lineBuf != p){
				break;
			}
			printf("Invalid Input\n");
		}
		array->dataPtr[i] = n;
	}
}

void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void sortIntArray(struct IntArray *array){
	for(int i = 0; i < array->length; i++){
		int switcher = 1;
		for(int j = 0; j < array->length - 1; j++){
			if(array->dataPtr[j] > array->dataPtr[j+1]){
				swap(&array->dataPtr[j], &array->dataPtr[j+1]);
				switcher = 0;
			}
		}
		if(switcher){
			break;
		}
	}
}

void printArray(struct IntArray *array){
	printf("[");
	for(int i = 0; i < array->length; i++){
		if(i < array->length - 1){
			printf("%d, ", array->dataPtr[i]);
			continue;
		}
		printf("%d", array->dataPtr[i]);
	}
	printf("]\n");
}

int main(){
	int length;
	char lineBuf[10];
	char *p = NULL;
	while(1){
		printf("Enter length: ");
		fgets(lineBuf, sizeof(lineBuf), stdin);
		length = strtol(lineBuf, &p, 10);
		if(lineBuf != p){
			break;
		}
		printf("Invalid Input\n");
	}
	struct IntArray *head = mallocIntArray(length);
	readIntArray(head);
	sortIntArray(head);
	printArray(head);
	freeIntArray(head);
}
