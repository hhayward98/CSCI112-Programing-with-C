#include <stdio.h>


int main() {
	int array[100], position, c, n, value;

	printf("Enter number of elements in array\n");
	scanf("%d", &n);

	printf("enter %d elements\n", n);

	for (c = 0; c < n; c++){
		scanf("5d", &array[c]);
	}

	printf("enter the locatioc where you wish to insert an element\n");
	scanf("%d", &position);

	printf("enter the value to insert\n");
	scanf("%d", &value);


	for (c = n -1; c >= position -1; c--) {
		array[c+1] = array[c];

	}
	array[position-1] = value;

	printf("results of array is\n");

	for (c = 0; c <= n; c++) {
		printf("%d\n", array[c]);
	}
	return(0);

}
