/*Experiment 7: Implementation of Queue using Linked List
 *Author: Ashvath S.P (Reg no: 2162014)
 *Date: 19/10/2022
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *front = NULL, *rear = NULL;

void display(struct node *ptr){
	int count = 1;
	if(front==NULL){
		printf("\nQueue is empty!\n");
	}
	else{
		printf("\nElements in queue:\n");
		while(ptr!=NULL){
			printf("Element %d: %d\n",count, ptr->data);
			ptr=ptr->next;
			count+=1;	
		}
	}
}

void enqueue(int val){
	struct node *newNode = (struct node *) malloc(sizeof(struct node));
	if(newNode==NULL){
		printf("\nQueue is full!\n");
	}
	else{
		newNode->data=val;
		newNode->next=NULL;
		if(front==NULL){
			front=rear=newNode; 
		}
		else{
			rear->next=newNode;
			rear=newNode;
		}
	}
}

int dequeue(){
	int val = -1;
	struct node *ptr;
	if(front==NULL){
		printf("\nQueue is empty!\n");
	}
	else{
		val=front->data;
		ptr=front;
		front=front->next;
		free(ptr);
	}
	return val;
}


int main(){
	int choice, element, delElement;
	
	printf("\nImplementation of Queue using Linked List\n");
	printf("\nOperations:\n1. Insert an element\n2. Delete an element\n3. Display elements\n4. Exit\n");
	
	do{
		printf("\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				printf("\nEnter element: ");
				scanf("%d",&element);
				enqueue(element);
				printf("\nElement %d is inserted to queue\n", element);
				break;
			}
			case 2:{
				delElement = dequeue();
				if(delElement == -1){
					break;
				}
				else{
					printf("\nElement %d is deleted from queue\n",delElement);
				}
				break;
			}
			case 3: display(front); break;
			case 4: exit(0); break;
			default: printf("Invalid Choice!");
		}
	}while(choice<4);

	return 0;
}
