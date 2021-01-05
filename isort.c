#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void shift_element(int* arr, int i) {
	while (i > 0) {
		*(arr + i) = *(arr + i - 1);
		i--;
	}
}

void insertion_sort(int* arr, int len) {
	int i, value, j;
	/*loop over all the elements
		inside the arr */
	for (i = 1; i < len; i++) {
		value = *(arr + i);
		j = i - 1;

		/* Move elements of arr , that are
		  greater than value , to one position ahead
		  of their current position */
		while (j >= 0 && *(arr + j) > value) {
	*(arr + j + 1) = *(arr + j);
			j = j - 1;
		}
		*(arr + j + 1) = value;
	}
}

