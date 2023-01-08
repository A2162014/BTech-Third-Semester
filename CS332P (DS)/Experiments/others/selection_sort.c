#include <stdio.h>
#define SIZE 100
int main()
{
	int array[SIZE], num, i, j, position, temp;
	
	printf("Selection Sort\n");
	
	printf("\nEnter number of elements: ");
	scanf("%d", &num);
	
	printf("\nEnter %d Numbers: ", num);
	for (i = 0; i < num; i++)
		scanf("%d", &array[i]);

	printf("\nOriginal Array: \n", num);
	for (i = 0; i < num; i++)
		printf("\t%d\t", array[i]);
	
	for(i = 0; i < num - 1; i++)
	{
		position = i;
		for(j = i + 1; j < num; j++)
		{
			if(array[position] > array[j])
			position = j;
		}
		if(position != i)
		{
			temp = array[i];
			array[i] = array[position];
			array[position] = temp;
		}
	}
	
	printf("\nSorted Array: \n");
	for(i = 0; i < num; i++)
		printf("\t%d\t", array[i]);
		
	printf("\n");
	
	return 0;
}
