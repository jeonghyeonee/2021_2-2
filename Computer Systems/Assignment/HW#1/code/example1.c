#include<stdio.h>

int main()
{
	printf("\n\n\t\tStudytonight - Best palce to learn\n\n\n");
	int array[100], position, c, n, value;

	printf("\n\nEnter number of elements in array:");
	scanf("%d", &n);

	printf("\n\nEnter %d elements\n", n);
	for(c=0; c < n; c++)
		scanf("%d", &array[c]);

	printf("\n\nEnter the location where you want to insert new element: ");
	scanf("%d", &value);

	printf("\n\nEnter the value to insert:");
	scanf("%d", &array[value]);

	// shifting the elements from (position to n) to right
	for(c=n-1; c >= position-1; c--)
		array[c+1] = array[c];

	array[position -1]= value;	// inserting the viven vlaue

	printf("\n\nResultant array is: ");
	/*
	 * the array size gets invresed by 1
	 * afther insertion of the element
	 */

	for(c=0; c<=n; c++)
		printf("%d ", array[c]);

	printf("\n\n\t\t\tCoding is Fun !\n\n\n");
	return 0;
}
