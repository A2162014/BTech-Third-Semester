//Exp 10: Implementation of Quick sort algorithm
//Compiled by: Ashvath S.P
//Date: 09/11/2022

#include<stdio.h>
#define MAX_SIZE 10

void quickSort(int array[], int first, int last){
	int i, j, pivot, temp;
	
	if(first < last){
		pivot = first;
		i = first;
		j = last;
		
		while(i < j){
			while(array[i] <= array[pivot] && i < last)
				i++;
			
			while(array[j] > array[pivot])
				j--;
			
			if(i < j){
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
		
		temp = array[pivot];
		array[pivot] = array[j];
		array[j] = temp;
		
		quickSort(array, first, j-1);
		quickSort(array, j+1, last);
	}
}

void printArray(int Array[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", Array[i]);
	printf("\n");
}

int main(){
	int array[MAX_SIZE], array_size, i;

	printf("Sorting using Quick Sort Algorithm\n");

	printf("\nEnter number of elements: ");
	scanf("%d", &array_size);
	
	printf("\nEnter %d elements: ", array_size);
	for (i = 0; i < array_size; i++)
		scanf("%d", &array[i]);
		
	printf("\nUnsorted array: \n");
	printArray(array, array_size);

	quickSort(array, 0, array_size-1);

	printf("\nSorted array: \n");
	printArray(array, array_size);
	
	return 0;
}
