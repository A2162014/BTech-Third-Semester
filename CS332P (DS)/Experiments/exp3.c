/*Experiment 3: Evaluation of Postfix expression using Stack
 *Author: Ashvath S.P (Reg no: 2162014)
 *Date: 10/08/2022
 */

//header file
#include <stdio.h>
#include <stdbool.h>

//global variables
int stack[100], top = -1;

//declaring functions
void push(int);
int pop();
bool checkIfNum(char);
void calculateExp(int, int, char);

//function to insert an element into the stack
void push(int item)
{
    stack[++top] = item;
}

//function to remove an element from the stack
int pop()
{
    return stack[top--];
}

//function to check if the character from the expression is numeric
bool checkIfNum(char y)
{
    return (y >= '0' && y <= '9');	
}

//function to calculate postfix expression
void calculateExp(int n1, int n2, char operator)
{
	int result;
	
	switch(operator)
    {
        case '+':	result = n1 + n2;	break;
        case '-':	result = n2 - n1;	break;
        case '*':	result = n1 * n2;	break;
        case '/':	result = n2 / n1;	break;
    }

	push(result);
}

//main program
int main()
{
    char post_exp[100], *p;
    int num1, num2, num;
    
	printf("Enter valid postfix expression: ");
    scanf("%s",post_exp);
    
    p = post_exp;
    
	while(*p != '\0')	/* run loop till the end of infix expression */
    {
    	if(checkIfNum(*p))
        {
            num = *p - 48;
            push(num);
        }
        else
        {
            num1 = pop();
            num2 = pop();
			calculateExp(num1, num2, *p);
        }
        p++;
    }
    
    printf("\nThe result of expression is %d\n\n", pop());
    
	return 0;
}
