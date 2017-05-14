#include <stdio.h>
#include <stdlib.h>

int binary_search ( int a[], int key, int low, int high) {

	if (low > high) {
		return high;
	}

	int mid = (low + high) / 2;

	if (key == a[mid]) {
		return mid;
	}

	if (key < a[mid]) 
		return binary_search(a, key, low, mid-1);
	else
		return binary_search(a, key, mid+1, high);

	return 0;
	
}

int main(void) {

	int array[10] = { 1, 3, 5, 7, 9, 11 };

	int location = binary_search (array, 1, 0, 5);

	if (1 == array[location]) {
		printf("found the item\n");
	} else {
		printf("not found the item\n");

	}

}

