#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int array [] = {64, 34, 25, 12, 22, 11, 90};;
	int size = sizeof(array)/sizeof(int);
	printf("before iteration array is\n");
	for (int j = 0; j < size; j++) {
		printf("%d ",array[j]);
	}
	printf("\n");
	for (int j = 0;  j < size-1; j++) {
		int swap = 0;
		for (int i = 0; i < size-1-j ; i++) {
			if ( array[i] > array[i+1] ) {
				int temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
				swap = 1;
			}
		}
		if (!swap) {
			//already done
			break;
		}
	}
	
	for (int j = 0; j < size; j++) {
		printf("%d ",array[j]);
	}
	return 0;
}
