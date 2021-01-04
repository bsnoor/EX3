#include <stdio.h>
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


int main() {
int arr[9], i, value;
int length = sizeof(arr) / sizeof(*(arr + 1));
//insert values into array
for (i = 0; i < length; i++)
{
	printf("arr[%d] = ", i);
    scanf("%d", &value);
    *(arr+i) = value;
}

//use function to sort the array
insertion_sort(arr, length);
for (i = 0; i < length; i++)
{
	printf("%d, ",*(arr + i));
}
	return 0;
}
