#include <stdio.h>

void swap(int *x, int *y);
void quick_sort(int a[], int length);
void quick_sort_recursion(int a[], int low, int high);
int partition(int a[], int low, int high);

int main(){
	int array[] = {9,1,6,4,3,7,2,8,5,0};
	int length = 10;
	
	quick_sort(array, length);
	
	for (int i = 0; i < length; i++)
		printf("%d ", array[i]);
	printf("\n");
	
	return 0;
}

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void quick_sort(int a[], int length){
	quick_sort_recursion(a, 0, length - 1);
}

void quick_sort_recursion(int a[], int low, int high){
	if (low < high){
		int pivot_index = partition(a, low, high);
		quick_sort_recursion(a, low, pivot_index - 1);
		quick_sort_recursion(a, pivot_index + 1, high);
	}
}

int partition(int a[], int low, int high){
	int pivot_value = a[high];
	
	int i = low;
	
	for (int j = low; j < high; j++){
		if(a[j] <= pivot_value){
			swap(&a[i], &a[j]);
			i++;
		}
	}
	swap(&a[i], &a[high]);
	
	return i;
}

