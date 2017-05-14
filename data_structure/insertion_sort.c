#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int array [] = {64, 34, 25, 12, 22, 11, 90};;
	int size = sizeof(array)/sizeof(int);

	printf("before array is\n");
	for (int j = 0; j < size; j++) {
		printf("%d ",array[j]);
	}
	printf("\n");

	int key, j;
	for (int i = 1; i < size; i++) {
		key = array[i];
		
		j = i - 1;
		while ( j >= 0 && array[j] > key) {
			array[j+1] = array[j];
			j = j -1;
		}
		array[j+1] = key;
	}

	printf("after array is\n");
	for (int j = 0; j < size; j++) {
		printf("%d ",array[j]);
	}
	return 0;
}
