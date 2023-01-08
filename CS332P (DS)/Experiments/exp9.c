//Exp 9: Implementation of Merge Sort Algorithm
//Compiled by: Ashvath S.P
//Date: 02/11/2022
 
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

// Merges two subarrays of array[].
// First subarray is array[left..mid]
// Second subarray is array[mid+1..right]
void merge(int array[], int left, int mid, int right)
{
	int i, j, k;
	int num1 = mid - left + 1;
	int num2 = right - mid;

	/* create temp arrays */
	int leftArray[num1], rightArray[num2];

	/* Copy data to temp arrays leftArray[] and rightArray[] */
	for (i = 0; i < num1; i++)
		leftArray[i] = array[left + i];
	for (j = 0; j < num2; j++)
		rightArray[j] = array[mid + 1 + j];

	/* Merge the temp arrays back into array[left..right]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = left; // Initial index of merged subarray
	while (i < num1 && j < num2) {
		if (leftArray[i] <= rightArray[j]) {
			array[k] = leftArray[i];
			i++;
		}
		else {
			array[k] = rightArray[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of leftArray[], 
	if there are any */
	while (i < num1) {
		array[k] = leftArray[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of rightArray[], 
	if there are any */
	while (j < num2) {
		array[k] = rightArray[j];
		j++;
		k++;
	}
}

/* left is for left index and right is right index 
of the sub-array of array to be sorted */
void mergeSort(int array[], int left, int right)
{
	if (left < right) {
		/*Same as (left + right) / 2, but avoids overflow
		for large l and h */
		int mid = left + (right - left) / 2;

		// Sort first and second halves
		mergeSort(array, left, mid);
		mergeSort(array, mid + 1, right);
		
		merge(array, left, mid, right);
	}
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int Array[], int size)
{
	int i;
	for (i = 0; i < size; ++i)
		printf("%d ", Array[i]);
	printf("\n"); 
}

/* Driver code */
int main()
{
	int array[MAX_SIZE], array_size, i;

	printf("Sorting using Merge Sort Algorithm\n");
	
	printf("\nEnter number of elements: ");
	scanf("%d", &array_size);
	
	printf("\nEnter %d elements: ", array_size);
	for (i = 0; i < array_size; i++)
		scanf("%d", &array[i]);
				
	printf("\nUnsorted array: \n");
	printArray(array, array_size);

	mergeSort(array, 0, array_size - 1);

	printf("\nSorted array: \n");
	printArray(array, array_size);
	return 0;
}

