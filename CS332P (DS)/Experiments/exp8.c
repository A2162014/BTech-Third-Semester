//Exp:8 - Implementation of Hash Table with Linear Probing
//Author: Ashvath S.P
//Date: 02/11/2022

#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

int hash_table[TABLE_SIZE], hash_key, i;

void hash_func(int);
void insert(int);
void display(void);
void search(int);

void hash_func(int key){
	hash_key = key % TABLE_SIZE;
}

void insert(int num){	
	hash_func(num);
	
	for(i = 0;i < TABLE_SIZE; i++){	
		int myIndex = (hash_key + i) % TABLE_SIZE;
		if(hash_table[myIndex] == '\0'){
			hash_table[myIndex] = num;
			break;
		}
	}
	
	if(i == TABLE_SIZE)
		printf("\n\tElement %d cannot be inserted to the Hash Table\n", num);
	else
		printf("\n\tElement %d is inserted to the Hash Table\n", num);
}

void display(){
	for(i = 0;i < TABLE_SIZE; i++){
		if (hash_table[i] == '\0')
			printf("\n\t\t   %d \t\t    __", i, hash_table[i]);
		else
			printf("\n\t\t   %d \t\t    %d", i, hash_table[i]);
	}
	
	printf("\n");
}

void search(int num){	
	hash_func(num);
	
	for(i = 0;i < TABLE_SIZE; i++){
		int myIndex = (hash_key + i) % TABLE_SIZE;
		if(hash_table[myIndex] == num){
			printf("\n\tElement %d is found in Hash Table at index %d\n", num, myIndex);
			break;
		}
	}
	
	if(i == TABLE_SIZE)
		printf("\n\tElement %d is not found in Hash Table\n", num);
}

int main(){
	int choice, element;
	
	printf("----------------------------------------------------------\n");
	printf("-+-+-+-+-+-+-+HASHING USING LINEAR PROBING+-+-+-+-+-+-+-+-\n");
	printf("----------------------------------------------------------\n");

	printf("\n\tMENU \n\t\t1. Insert \n\t\t2. Display \n\t\t3. Search \n\t\t4. Exit \n");
	
	do{
		printf("\n\tChoice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:{
				printf("\n----------------------------------------------------------\n");
				
				printf("\n\tEnter an element: ");
				scanf("%d", &element);
				
				insert(element);
				
				printf("\n----------------------------------------------------------\n");
				break;
			}
			case 2:{
				printf("\n----------------------------------------------------------\n");
				
				printf("\n\tHash Table: \n");
				printf("\n\t\t Index \t\t Element\n");
				
				display();
				
				printf("\n----------------------------------------------------------\n");
				break;
			}
			case 3:{
				printf("\n----------------------------------------------------------\n");
				
				printf("\n\tEnter search element: ");
				scanf("%d", &element);
				
				search(element);
				
				printf("\n----------------------------------------------------------\n");
				break;
			}
			case 4:{
				printf("\n----------------------------------------------------------\n");
				printf("-+-+-+-+-+-+-+-+-+-+-+END OF PROGRAM+-+-+-+-+-+-+-+-+-+-+-\n");
				printf("----------------------------------------------------------\n");
				exit(0);
				break;
			}
			default:{
				printf("\n----------------------------------------------------------\n");
				printf("-+-+-+-+-+-+-+-+-+-+-+INVALID INPUT+-+-+-+-+-+-+-+-+-+-+-+\n");
				printf("----------------------------------------------------------\n");
				break;
			}
		}
	}while(choice < 4);
	
	return 0;
}
