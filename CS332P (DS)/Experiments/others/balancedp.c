//Experiment 2: Balanced Parentheses using Stack 
//Author: Ashvath S.P (Reg no: 2162014)
//Date: 03/08/2022

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 30

int top=-1;
int stack[MAX];

void push(char);
char pop();
int match(char a,char b);
int check(char []);
int isEmpty();
int isFull();

int main()
{
    char exp[MAX];
    int valid;
    printf("Enter an algebraic expression : ");
    gets(exp);
    valid=check(exp);
    if(valid==1)
        printf("Valid expression\n");
    else
        printf("Invalid expression\n");
	return 0;
}

int check(char exp[])
{
    int i;
    char temp;
    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            push(exp[i]);
        if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
            if(isEmpty())    /*stack empty*/
            {
                printf("Right parentheses are more than left parentheses\n");
                return 0;
            }	
            else
            {
                temp=pop();
                if(!match(temp, exp[i]))
                {
                    printf("Mismatched parentheses are : ");
                    printf("%c and %c\n",temp,exp[i]);
                    return 0;
                }
            }
    }	
    if(isEmpty()) /*stack empty*/
    {
        printf("Balanced Parentheses\n");
        return 1;
    }
    else
    {
        printf("Left parentheses more than right parentheses\n");
        return 0;
    }
}

int match(char a,char b)
{
    if(a=='[' && b==']' || a=='{' && b=='}' || a=='(' && b==')')
        return 1;
    else
		return 0;
}

void push(char item)
{
    if(isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[top++]=item;
}

char pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return(stack[top--]);
}

int isEmpty(){
	return top == -1;
}

int isFull(){
	return top == (MAX-1);
}
