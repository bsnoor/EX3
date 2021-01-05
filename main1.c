#include <stdio.h>
#include "isort.c"
int main() {
int arr[50], i, value;
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
