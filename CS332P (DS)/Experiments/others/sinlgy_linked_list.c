/* 
 * C program to Implement the Singly Linked List
 */
 
#include<stdio.h>
#include<malloc.h>
 
//type declaration of a node
struct node
{
    int data;
    struct node* next;
};
 
//global head pointer
struct node* head = NULL;
 
//Declaring functions 
struct node* create_node(int);
void insert_at_beginning(int);
void insert_at_end(int);
void insert_at_position(int, int);
void delete_at_beginning();
void delete_at_end();
void delete_at_position(int);
void print_from_beginning();
void print_from_end(struct node*);
void search_data(int);
void update_node_data(int, int);
void empty_message(void);
int size_of_list();
int getData();
int getPosition();

int main()
{
    char user_active = 'Y';
    int user_choice;
    int data, position;

	printf("----------------------------------\n"
			"\n\tSingly Linked List\n"
			"\n----------------------------------\n"
			"\nOperations:\n"
			"\n1. Insert a node at beginning"
			"\n2. Insert a node at end"
			"\n3. Insert a node at given position"
			"\n4. Delete a node from beginning"
			"\n5. Delete a node from end"
			"\n6. Delete a node from given position"
			"\n7. Display list from beginning"
			"\n8. Display list from end"
			"\n9. Search a node data"
			"\n10. Update a node data"
			"\n11. Exit\n");
    
	do
    {
		printf("\nEnter your choice : ");
		scanf("%d", &user_choice);

        switch(user_choice)
        {

            case 1:
                printf("\nCurrent Operation: Inserting a node at beginning\n");
                data = getData();
                insert_at_beginning(data);
                break;
 
            case 2:
                printf("\nCurrent Operation: Inserting a node at end\n");
                data = getData();
                insert_at_end(data);
                break;
 
            case 3: 
                printf("\nCurrent Operation: Inserting a node at the given position\n");
                data = getData();
                position = getPosition();
                insert_at_position(data, position);
                break;
 
            case 4: 
                printf("\nCurrent Operation: Deleting a node from beginning\n");
                delete_at_beginning();
                break;
 
            case 5: 
                printf("\nCurrent Operation: Deleting a node from end\n");
                delete_at_end();
                break;
 
            case 6: 
                printf("\nCurrent Operation: Delete a node from given position\n");
                position = getPosition();
                delete_at_position(position);
                break;
 
            case 7: 
                printf("\nCurrent Operation: Dsiplaying the list from beginning\n");
                print_from_beginning();
                break;
 
            case 8: 
                printf("\nCurrent Operation: Dsiplaying the list from end\n");
                print_from_end(head);
                break;
 
            case 9:
                printf("\nCurrent Operation: Searching the node data\n");
                data = getData();
                search_data(data);
                break;
 
            case 10:
                printf("\nCurrent Operation: Updating the node data\n");
                data = getData();
                position = getPosition();
                update_node_data(data, position);
                break;
 
            case 11:
                printf("\nStatus: Program was terminated\n");
                return 0;
 
            default:
                printf("\nResult: Invalid Choice!\n");
        }
    }while(user_choice <= 11);
 
    return 0;
}
 
/* 
* Function will show an empty list message
*/

void empty_message()
{
    printf("\nStatus: List is Empty!\n");
}
 
/* 
* Function will show the memory allocation failure
*/

void memory_message()
{
    printf("\nStatus: Memory can't be allocated!\n");
}

/* 
* Returns the size of the list
*/

int size_of_list()
{
    struct node* temp = head;
    
	int count = 0;
 
    while(temp != NULL)
    {
        count += 1;
        temp = temp->next;
    }
    
	return count;
}
 
/* 
* Getting node data from the user
*/

int getData()
{
    int data;
    
	printf("\nEnter Data: ");
    scanf("%d", &data);
 
    return data;
}
 
/* 
* Getting the position of the node from the user
*/

int getPosition()
{
    int pos;
 
    printf("\nEnter Position: ");
    scanf("%d", &pos);
 
    return pos;
}

/* 
* Function will create a new node and return the address of that node
*/

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
 
/* 
* Insert the new node at the beginning of the list
*/

void insert_at_beginning(int data)
{
    struct node* new_node = NULL;
    
    new_node = create_node(data);
    
    if(new_node != NULL)
    {
	    new_node->next = head;
        head = new_node;
	    printf("\nStatus: Node with data %d inserted\n", data);
    }
    else
    {
        memory_message();
	}
}
 
/* 
* Insert the new node at the end of the list
*/

void insert_at_end(int data)
{
    struct node* new_node = NULL;
    
    new_node = create_node(data);
 
    if(new_node != NULL)
    {
        //if list is empty
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
 
            //link the last node next pointer to the new node
            last->next = new_node;
        }
        printf("\nStatus: Node with data %d inserted\n", data);
    }
    else
    {
        memory_message();
	}
}

/* 
* Insert the new node at the given position 
*/

void insert_at_position(int data, int pos)
{
    int list_size = 0;
	struct node* new_node = NULL;
    
    //calculate the size of the list
    list_size = size_of_list();
    new_node = create_node(data);
    
    //if the list is empty and the position is greater than the 1 or the list is not empty and the position is out of range
    if((head == NULL && (pos <= 0 || pos > 1)) || (head != NULL && (pos <= 0 || pos > list_size)))
    {
        printf("\nStatus: Invalid position!\n");
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
 
        //if the position is 1 then insertion at the beginning
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
        printf("\nStatus: Node with data %d was inserted at position %d\n", data, pos);
    }
    else
    {
        memory_message();
	}
}

/* 
* Delete the node from the beginning of the list
*/

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
	 
	    //move head pointer to the next node to the head
	    head = head->next;
	    free(temp);
    	printf("\nStatus: Node with data %d was deleted\n", data);  	
	}
}

/* 
* Delete the node from the ending of the list 
*/

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
    	printf("\nStatus: Node with data %d was deleted\n", data);  	
	}
}

/* 
* Deleting the node from the given position
*/

void delete_at_position(int pos)
{
    //calculate the size of the list
    int list_size = 0;
    list_size = size_of_list();
 
    // if the position is out of range
    if(pos <= 0 || pos > list_size)
    {
        printf("\nStatus: Invalid position!\n");
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
	    printf("\nStatus: Node with data %d was deleted from position %d\n", data, pos);	
	}
}
 
/* 
* Search the node with given data in the list
*/

void search_data(int data)
{
    int position = 0;
    int flag = 0;
 
    struct node* temp = head;
 
    while(temp != NULL)
    {
        position += 1;
        if(temp->data == data)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
 
    if(flag == 0)
    {
        printf("\nStatus: Node with data %d was not found!\n", data);
    }
    else 
    {
        printf("\nStatus: Node with data %d was found at position %d\n", data, position);
    }
}
 
/* 
* Update the node with the given new data
*/

void update_node_data(int new_data, int pos)
{
    //calculate the size of the list
    int list_size = 0;
    list_size = size_of_list();
 
    // if the position is out of range
    if(pos <= 0 || pos > list_size)
    {
        printf("\nStatus: Invalid position!\n");
        return;
    }
 
    struct node* temp = head;
    int count = 1;
 
    while(count < pos)
    {
        temp = temp->next;
        count += 1;
    }
 
    temp->data = new_data;
    printf("\nStatus: Updated node data is %d\n", new_data);
}
 
/* 
* Prints the data from the start of the list
*/

void print_from_beginning()
{
    if(head == NULL)
    {
        empty_message();
        return;
    }
    else
    {
	    struct node* temp = head;
	 
	    while(temp != NULL)
	    {
	        printf("%d --> ", temp->data);
	        temp = temp->next;
	    }    	
	}
}
 
/* 
* Prints the list from the end of the list
*/

void print_from_end(struct node* head)
{
    if(head == NULL)
    {
        return;
    }
    else
    {
	    print_from_end( head->next );
	    printf("%d --> ", head->data);   	
	}
}
