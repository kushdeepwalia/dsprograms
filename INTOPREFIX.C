#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<windows.h>
#define SIZE 100
char stack[SIZE];
int top = -1;
void push(char item)
{
    if(top==SIZE-1)
    {
        printf("\n Overflow Error");
        return;
    }
    top++;
    stack[top] = item;
}
char pop()
{
    char item ;
    if(top==-1)
    {
        printf("\n Underflow Error");
        Sleep(5000);
        exit(1);
    }
    item = stack[top];
    top--;
    return(item);
}
int is_operator(char symbol)
{
    if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
        return 1;
    else
        return 0;
}
int precedence(char symbol)
{
    if(symbol == '^')
        return 3;
    else if(symbol == '*' || symbol == '/')
        return 2;
    else if(symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}
char *InfixToPostfix(char infix_exp[], char postfix_exp[])
{
    int i,j;
    char item,x;
    push('(');
    strcat(infix_exp,")");
    i=0;
    j=0;
    item=infix_exp[i];
    while(item != '\0')
    {
        if(item == '(')
            push(item);
        else if(isdigit(item) || isalpha(item))
        {
            postfix_exp[j] = item;
            j++;
        }
        else if(is_operator(item) == 1)
        {
            x=pop();
            while(is_operator(x) == 1 && precedence(x)>= precedence(item))
            {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        }
        else if(item == ')')
        {
            x = pop();
            while(x != '(')
            {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
        }
        else
        {
            printf("\nInvalid infix Expression.\n");
            Sleep(5000);
            exit(1);
        }
        i++;
        item = infix_exp[i];
    }
    postfix_exp[j] = '\0';
    return postfix_exp;
}
void InfixToPrefix(char infix_exp[], char prefix_exp[])
{
    int l,i,j;
    char postfix_exp[SIZE],temp;
    l=strlen(infix_exp);
    strrev(infix_exp);
    for (int i = 0; i < l; i++) {

        if (infix_exp[i] == '(') {
            infix_exp[i] = ')';
            i++;
        }
        else if (infix_exp[i] == ')') {
            infix_exp[i] = '(';
            i++;
        }
    }
    strcpy(prefix_exp,InfixToPostfix(infix_exp,postfix_exp));
    l=strlen(prefix_exp);
    strrev(prefix_exp);
}
int main()
{
    char infix[SIZE], prefix[SIZE];
    printf("\nEnter Infix expression : ");
    gets(infix);
    InfixToPrefix(infix,prefix);
    printf("Prefix Expression: ");
    printf("\n Kushdeep Singh");
    puts(prefix);
    Sleep(5000);
    return 0;
}
