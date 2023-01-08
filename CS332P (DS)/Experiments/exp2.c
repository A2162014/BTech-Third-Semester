/*Experiment 2: Infix to Postfix Converter using Stack
 *Author: Ashvath S.P (Reg no: 2162014)
 *Date: 27/07/2022
 */

//header file
#include <stdio.h>
#include <stdbool.h>

//global variable declarations
char stack[100];
int top = -1;

//function declarations
bool isEmpty();
void push(char);
char pop();
char peek();
bool checkIfAlnum(char);
int getPriority(char);

//function to check if Stack is empty
bool isEmpty()
{
    return (top <= -1);
}

//function to append the elements into the Stack
void push(char item)
{
	stack[++top] = item;
}

//function to remove the elements from the Stack
char pop()
{
	return stack[top--];
}

//function to get element in Stack at top
char peek()
{
    return stack[top];
}

//function to check if the character from the expression is alphanumeric
bool checkIfAlnum(char item)
{
    return ((item >= 'a' && item <= 'z') || (item >= 'A' && item <= 'Z') || (item >= '0' && item <= '9'));	
}

//function to get the priority of the Arthematic operators
int getPriority(char operator)
{
    switch (operator) 
    {
		case '-':	return 1;
		case '+':	return 2;  
	    case '%':	return 3;
		case '/': 	return 4;
		case '*':	return 5;
	    case '^': 	return 6;
	    default:	return -1;
	} 
}

//main program
int main()
{
    char *i, item, infix[100];
	int choice;
    
    printf("Infix to Postfix Converter\n");
	printf("\nOperations:\n\n1)Start\n2)Stop\n");

	do
	{
		printf("\nEnter Choice: ");
		scanf("%d",&choice);
		switch (choice)
		{
		case 1:
		{
			printf("\nEnter an Infix expression: ");
		    scanf("%s",infix);
		    
		    printf("\nPostfix expression: ");
		    
		    i = infix;
		    
		    while(*i != '\0')	/* run loop till the end of infix expression */
		    {
		        if(checkIfAlnum(*i)) 
		            printf("%c",*i);
        		else if(*i == '(')
		            push(*i);
		        else if(*i == ')')
		        {
		            while((item = pop()) != '(')
		                printf("%c", item);
		        }
		        else
		        {
		            while(getPriority(peek()) >= getPriority(*i))
		                printf("%c",pop());
		            push(*i);
		        }
		        i++;
		    }
		    
		    while(!isEmpty())
		    {
		        printf("%c",pop());
		    }

			printf("\n");
			
			break;
		}			
		case 2:	break;
		default:	printf("Invalid input!");	break;
		}
	}while(choice <= 1);
	
	return 0;
}
