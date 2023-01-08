/*Experiment 1: Implementation of Stack Using Array
 *Author: Ashvath S.P (Reg no: 2162014)
 *Date: 20/07/2022
 */

//header file
#include <stdio.h>
#include <stdbool.h>

//global variable declarations
int stack[100], top = -1, size, item;

//function declarations
bool isFull();
bool isEmpty();
void push(void);
void pop(void);
int peek(void);
void display(void);

//function to check if Stack is Full
bool isFull()
{
	return (top >= size-1);	
}

//function to check if Stack is empty
bool isEmpty()
{
	return (top <= -1); 
}

//function to append the element into the Stack
void push(){
	if(isFull())
	{
		printf("\nStack Overflow!\n");
	}
	else
	{
		printf("\nEnter element: ");
		scanf("%d",&item);
		
		top++;
		stack[top] = item;
		
		printf("\nInserted element %d in Stack\n",item);
	}
}

//function to remove the element from the Stack
void pop(){
	if(isEmpty())
	{
		printf("\nStack Underflow!\n");
	}
	else
	{
		printf("\nDeleted element %d from Stack...\n",peek());
		top--;
	}
}

//function to get element in Stack at top
int peek(){
	return stack[top];
} 

//function to display elements in the Stack
void display()
{
	int index;
	
	if(isEmpty())
	{
		printf("\nEmpty Stack!\n");
	}
	else
	{
		for(index = top ; index >= 0 ; index--)
		{
			printf("\n\t%d\n",stack[index]);
		}
	}
}

//main program
int main()
{
	int choice;
	
	printf("Implementation of Stack using Array\n");
	printf("\nOperations\n");	
	printf("\n1.Insert an element\n2.Delete an element\n3.Retrieve top element\n4.Display elements\n5.Exit\n");
	printf("\nEnter size of stack: ");
	scanf("%d",&size);
	
	do
	{
		printf("\nChoose operation: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	push();	break;
			case 2:	pop();	break;
			case 3:	printf("\nCurrent Peek is %d\n",peek());	break;
			case 4:	display();	break;
			case 5:	break;
			default:	printf("Invalid input!");	break;
		}
	}while(choice <= 4);
	
	return 0;
}
