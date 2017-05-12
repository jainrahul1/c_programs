// program to set, clear, toggle, check and change nth bit of a number

#include <stdio.h>

void binary_rep (int num) {
	if (num == 0)
		return;

	binary_rep (num/2);
	printf ("%d", num % 2);
	return;
}

void set_bit (int num, int pos) {
	int mask = 1 << pos;
	num = num | mask;
	binary_rep (num);
	return;
}


void clear_bit (int num, int pos) {
	int mask = ~(1 << pos);
	num = num & mask;
	binary_rep (num);
	return;
}

void toggle_bit (int num, int pos) {
	int mask = 1 << pos;
	num = num ^ mask;
	binary_rep (num);
	return;
}

int check_bit (int num, int pos) {
	int mask = 1 << pos;
	num = num & mask;
	if (num) {
		return 1;
	} else {
		return 0;
	}
}

void change_bit (int num, int pos, int value) {
	int mask = ~(1 << pos);
	num = num & mask;
	num = num | ( value << pos);
	binary_rep (num);
	return;
}

int main (void) {
	int number;
	int position;
	int value;

	printf ("Enter the number\n");
	scanf ("%d", &number);
	printf ("Binary representation of the number is\n");
	binary_rep (number);

	printf ("\nEnter the position of bit to set (0th to nth)\n");
	scanf ("%d", &position);
	set_bit (number, position);
	
	printf ("\nEnter the position of bit to clear (0th to nth)\n");
	scanf ("%d", &position);
	clear_bit (number, position);

	printf ("\nEnter the position of bit to toggle (0th to nth)\n");
	scanf ("%d", &position);
	toggle_bit (number, position);

	printf ("\nEnter the position of bit to check (0th to nth)\n");
	scanf ("%d", &position);
	if (check_bit (number, position))
		printf("bit is 1\n");
	else
		printf("bit is 0\n");
	
	printf ("\nEnter the position of bit to change (0th to nth)\n");
	scanf ("%d", &position);

	printf ("Enter the desired value for the bit\n");
	scanf ("%d", &value);

	change_bit (number, position, value);
	printf("\n");

	return 0;
}
