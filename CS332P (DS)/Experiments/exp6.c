/*Experiment 6: Implementation of Stack using Linked List
 *Author: Ashvath S.P (Reg no: 2162014)
 *Date: 24/08/2022
 */

//header files
#include <stdio.h>  
#include <stdlib.h>
#include <stdbool.h>

//type declaration of a node
struct node   
{  
	int data;  
	struct node *next;  
}*top = NULL;  

//function declarations
bool isEmpty();
void push();  
void pop();
int peek(); 
void display();  

//function to check if Stack is empty
bool isEmpty()
{
	return (top == NULL);
}

//function to insert a node to Stack
void push()
{
    int item;  
    
	struct node *ptr = (struct node*) malloc(sizeof(struct node));   
    
	printf("\nEnter element: ");  
    scanf("%d",&item);  
    
	if(isEmpty())  
    {         
        ptr->data = item;  
        ptr->next = NULL;  
        top = ptr;  
    }   
    else   
    {  
        ptr->data = item;  
        ptr->next = top;  
        top = ptr;  
    }  
    printf("\nInserted Node with element %d to Stack\n", ptr->data); 
}  

//function to delete node from Stack  
void pop()  
{  
    int temp;  
    struct node *ptr;  
    
	if (isEmpty())  
    {  
        printf("\nStack is Underflow!\n");  
    }  
    else  
    {  
        temp = top->data;  
        ptr = top;  
        top = top->next;  
        printf("\nDeleted Node with element %d to Stack\n", ptr->data);
		free(ptr);     
    }  
}  

//function to retrieve top node from Stack
int peek()
{
	if(isEmpty())
		printf("\nEmpty Stack!\n");
	else
		printf("\nCurrent Peek is %d\n", top->data);
}

//function to display node in Stack
void display()  
{  
    struct node *ptr;  
    
	ptr = top;  
    
	if(isEmpty())  
    {  
        printf("\nEmpty Stack!\n");  
    }  
    else  
    {
		printf("\n"); 
        while(ptr != NULL)  
        {  
            printf(" <-- %d", ptr->data);  
            ptr = ptr->next;  
        }
		printf("\n");  
    }  
}

//main program 
void main()  
{
    int choice;     
    
	printf("Implementation of Stack using Linked List\n");
	printf("\nOperations:\n");  
	printf("1. Insert an element\n2. Delete an element\n3. Retrieve top element\n4. Display elements\n5.Exit\n"); 
	
	while(choice != 5)
    {  
        printf("\nEnter your choice: ");        
        scanf("%d",&choice);  
		switch(choice)  
        {  
            case 1: push(); break;  
            case 2: pop(); break;
            case 3: peek(); break;
			case 4: display(); break;
            case 5: break;
            default: printf("\nInvalid choice!\n");  
        }   
    }  
}  
