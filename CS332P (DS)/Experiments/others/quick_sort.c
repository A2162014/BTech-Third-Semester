//Exp 11: Implementation of Quick sort algorithm
//Compiled by: Ashvath S.P
//Date: 09/11/2022

#include<stdio.h>

void quickSort(int array[25], int first, int last){
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
	int array[] = { 55, 35, 25, 40, 30, 20, 15 };

	int array_size = sizeof(array) / sizeof(array[0]);

	printf("Sorting using Quick Sort Algorithm\n");
		
	printf("\nUnsorted array: \n");
	printArray(array, array_size);

	quickSort(array, 0, array_size-1);

	printf("\nSorted array: \n");
	printArray(array, array_size);
	
	return 0;
}
