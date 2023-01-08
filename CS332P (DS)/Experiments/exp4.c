/*Experiment 4: Implementation of Queue using Array
 *Author: Ashvath S.P (Reg no: 2162014)
 *Date: 17/08/2022
 */

//header file
#include <stdio.h>
#include <stdbool.h>   

//global variable declarations
int queue[100], front = -1, rear = -1, size;

//function declarations
bool isFull();
bool isEmpty();
void enQueue();  
void deQueue();  
void display();

//function to check if Queue is full
bool isFull()
{
	return (rear == size-1);
}

//function to check if Queue is empty
bool isEmpty()
{
	return (front == -1 || front > rear);
}

//function to insert an element to Queue
void enQueue()  
{  
	int item;
	
	printf("\nEnter element: ");  
	scanf("%d",&item);
	
	if(isFull())  
	{
		printf("\nQueue Overflow!\n");
		return;
	}  
	else if(front == -1 && rear == -1)  
	{  
		front = rear = 0;  
	}  
	else  
	{  
		rear++;  
	}
	
	queue[rear] = item;  
	
	printf("\nInserted element %d to Queue\n", item);
}

//function to delete an element from Queue
void deQueue()  
{  
	int item;
	
	if (isEmpty())  
	{  
		printf("\nQueue Underflow!\n");
	}
	else
	{  
		item = queue[front];
		
		if(front == rear)  
		{  
			front = rear = -1;  
		}  
		else   
		{  
			front++;  
		}  
		
		printf("\nDeleted element %d from Queue\n", item);  
	}
}  

//function to display elements in Queue
void display()  
{  
	int index;
	
	if(rear == -1)  
	{  
		printf("\nEmpty Queue!\n");  
	}  
	else  
	{     
		for(index = front ; index <= rear ; index++)  
		{  
			printf("\n\t%d\n",queue[index]);  
		}     
	}
}

//main program
int main()
{  
	int choice;
	
	printf("Implementation of Queue using Array\n");
	printf("\nOperations\n");		  
	printf("\n1.Insert an element\n2.Delete an element\n3.Display elements\n4.Exit\n");
	printf("\nEnter size of queue: ");
	scanf("%d",&size); 
	do{
		printf("\nEnter your choice: ");  
		scanf("%d",&choice);  
		switch(choice)
		{
			case 1: enQueue();	break;  
			case 2:	deQueue();	break;  
			case 3:	display();	break;  
			case 4:	break;  
			default:	printf("\nInvalid choice!\n");
		}
	}while(choice <= 3);
	
	return 0;
}
