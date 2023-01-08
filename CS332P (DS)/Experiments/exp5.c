/*Experiment 5: Implementation of Singly Linked List
 *Author: Ashvath S.P (Reg no: 2162014)
 *Date: 07/09/2022
 */

//header files
#include <stdio.h>
#include <stdlib.h>
 
//type declaration of a node
struct node
{
    int data;
    struct node* next;
}*head = NULL;
 
//function declarations
void empty_message();
void memory_message();
int getData();
int getPosition();
struct node* create_node(int);
void insert_at_beginning(int);
void insert_at_end(int);
void insert_at_position(int, int);
void delete_at_beginning(void);
void delete_at_end();
void delete_at_position(int);
void display();

//function to display message, "List is Empty!"
void empty_message()
{
    printf("\nList is Empty!\n");
}

//function to display message, "Memory can't be allocated!"
void memory_message()
{
    printf("\nMemory can't be allocated!\n");
}

//function to get data from the user
int getData()
{
    int data;
    
	printf("\nEnter Data: ");
    scanf("%d", &data);
 
    return data;
}

//function to get position of the node from the user
int getPosition()
{
    int pos;
 
    printf("\nEnter Position: ");
    scanf("%d", &pos);
 
    return pos;
}

//function to create a new node and return the address of that node
struct node* create_node(int data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
 
    if(new_node == NULL)
    {
        memory_message();
        return NULL;
    }
	else
	{
	    new_node->data = data;
	    new_node->next = NULL;
	    
	    return new_node;	
	}
}

//function to insert a node at the beginning of the List
void insert_at_beginning(int data)
{
    struct node* new_node = NULL;
    
    new_node = create_node(data);
    
    if(new_node != NULL)
    {
	    new_node->next = head;
        head = new_node;
	    printf("\nNode with data %d inserted at the beginning of the List\n", data);
    }
    else
    {
        memory_message();
	}
}

//function to insert a node at the end of the List
void insert_at_end(int data)
{
    struct node* new_node = NULL;
    
    new_node = create_node(data);
 
    if(new_node != NULL)
    {
        //if List is empty, insert node at beginning
        if(head == NULL)
        {
            head = new_node;
        }
        else 
        {
            struct node* last = head;
 
            //getting the last node
            while(last->next != NULL)
            {
                last = last->next;
            }
 
            //link the last node's next pointer to the new node
            last->next = new_node;
        }
        printf("\nNode with data %d inserted at the end of the List\n", data);
    }
    else
    {
        memory_message();
	}
}

//function to insert node at given position 
void insert_at_position(int data, int pos)
{
	struct node* new_node = NULL;
    
    new_node = create_node(data);
    
    //if the list is empty and (the position is greater than 1 or less than 0)
    if(head == NULL && (pos <= 0 || pos > 1))
    {
        printf("\nInvalid position!\n");
        return;
    }    
    else if(new_node != NULL)
    {
        struct node* temp = head;
        int count = 1;

		//getting the position-1 node
        while(count < pos-1)
        {
            temp = temp -> next;
            count += 1;
        }
   
        //if the position is 1, then insert at the beginning
        if(pos == 1)
        {
            new_node->next = head;
            head = new_node;
        }
        else 
        {
            new_node->next = temp->next;
            temp->next = new_node;
        }
        printf("\nNode with data %d was inserted at position %d of the List\n", data, pos);
    }
    else
    {
        memory_message();
	}
}

//function to delete node from the beginning of the List 
void delete_at_beginning()
{
    if(head == NULL) 
    {
        empty_message();
        return;
    }
    else
    {
	    struct node* temp = head;
	    int data = head->data;
	 
	    //move head pointer to the next node
	    head = head->next;
	    free(temp);
    	printf("\nNode with data %d was deleted from the beginning of the list\n", data);  	
	}
}


//function to delete node from the end of List
void delete_at_end()
{
    if(head == NULL)
    {
        empty_message();
        return;
    }
    else
    {
	    struct node* temp = head;
	    struct node* prev = NULL;
	    int data;
	 
	    //reaching the last node
	    while(temp->next != NULL)
	    {
	        prev = temp;
	        temp = temp->next;
	    }
	 
	    data = temp->data;
	 
	    //if there is only one node
	    if(temp == head)
	    {
	        free(temp);
	        head = NULL;
	    }
	    else 
	    {
	        free(temp);
	        prev->next = NULL;
	    }
    	printf("\nNode with data %d was deleted from the end of the List\n", data);  	
	}
}

//function to delete node from the position
void delete_at_position(int pos)
{
    //if the list is empty and (the position is greater than 1 or less than 0)
    if(head == NULL && (pos <= 0 || pos >= 1))
    {
        printf("\nInvalid position!\n");
        return;
    }
 	else
	{
	    struct node* temp = head;
	    struct node* prev = NULL;
	    int count = 1;
	 
	    while(count < pos)
	    {
	        prev = temp;
	        temp = temp->next;
	        count += 1;
	    }
	 
	    int data = temp->data;
	 
	    if(temp == head)
	    {
	        head = head->next;
	        free(temp);
	    }
	    else
	    {
	        prev->next = temp->next;
	        free(temp);
	    }
	    printf("\nNode with data %d was deleted from position %d of the List\n", data, pos);	
	}
}

//function to display node in the List
void display()
{
    if(head == NULL)
    {
        empty_message();
        return;
    }
    else
    {
	    struct node* temp = head;
	    
		printf("\n"); 
	    
		while(temp != NULL)
	    {
	        printf(" %d --> ", temp->data);
	        temp = temp->next;
	    }
		
		printf("\n");	
	}
}

//main program
int main()
{
    int user_choice, data, position;

	printf("Singly Linked List\n"
			"\nOperations:\n"
			"\n1. Insert a node at beginning"
			"\n2. Insert a node at end"
			"\n3. Insert a node at given position"
			"\n4. Delete a node from beginning"
			"\n5. Delete a node from end"
			"\n6. Delete a node from given position"
			"\n7. Display the list"
			"\n8. Exit\n");
    
	do{
		printf("\nEnter your choice : ");
		scanf("%d", &user_choice);

        switch(user_choice)
        {
            case 1:
                printf("\nCurrent Operation: Insert a node at beginning\n");
                data = getData();
                insert_at_beginning(data);
                break;
 
            case 2:
                printf("\nCurrent Operation: Insert a node at end\n");
                data = getData();
                insert_at_end(data);
                break;
 
            case 3: 
                printf("\nCurrent Operation: Insert a node at the given position\n");
                data = getData();
                position = getPosition();
                insert_at_position(data, position);
                break;
 
            case 4: 
                printf("\nCurrent Operation: Delete a node from beginning\n");
                delete_at_beginning();
                break;
 
            case 5: 
                printf("\nCurrent Operation: Delete a node from end\n");
                delete_at_end();
                break;
 
            case 6: 
                printf("\nCurrent Operation: Delete a node from given position\n");
                position = getPosition();
                delete_at_position(position);
                break;
 
            case 7: 
                printf("\nCurrent Operation: Display the list\n");
                display();
                break;
 
            case 8:	exit(0);
 
            default:
                printf("\nInvalid Choice!\n");
        }
    }while(user_choice <= 8);
 
    return 0;
}
