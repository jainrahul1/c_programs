#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int array [] = {5,2,7,1,10,9,15,11,3};
	int size = sizeof(array)/sizeof(int);

	printf("before array is\n");
	for (int j = 0; j < size; j++) {
		printf("%d ",array[j]);
	}
	printf("\n");

	for ( int i = 0; i < size-1; i++) {
		int min_index = -1;
		int min = array[i];
		for ( int j = i+1; j < size; j++) {
			if (min > array[j]) {
				min = array[j];
				min_index = j;
			}
		}
		int temp;
		temp = array[i];
		array[i] = array[min_index];
		array[min_index] = temp;
	}

	printf("after array is\n");
	for (int j = 0; j < size; j++) {
		printf("%d ",array[j]);
	}
	return 0;
}
