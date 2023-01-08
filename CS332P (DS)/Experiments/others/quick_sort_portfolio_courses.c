#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y);
void quick_sort(int array[], int length);
void quick_sort_recursion(int array[], int low, int high);
int partition(int array[], int low, int high);

int main(){
	int a[]= {10, 11, 23, 44, 8, 15, 3, 9, 12, 45, 56, 45, 45};
	int length = 13;
	
	quick_sort(a, length);
	
	for( int i = 0; i < length; i++)
		printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void quick_sort(int array[], int length){
	srand(time(NULL));

	quick_sort_recursion(array, 0, length - 1);
}

void quick_sort_recursion(int array[], int low, int high){
	if (low < high){
		int pivot_index = partition(array, low, high);
		quick_sort_recursion(array, low, pivot_index - 1);
		quick_sort_recursion(array, pivot_index + 1, high);
	}
}

int partition(int array[], int low, int high){
	int pivot_index = low + (rand() % (high - low));
	
	if (pivot_index != high)
		swap(&array[pivot_index], &array[high]);
	
	int pivot_value = array[high];
	
	int i = low;
	
	for (int j = low; j < high; j++){
		if (array[j] <= pivot_value){
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap (&array[i], &array[high]);
	
	return i;
}

