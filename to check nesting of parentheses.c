#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50
int top=-1;
int stack[MAX];
void push();
char pop();
int match(char a,char b);
int check();
main()
{
    char exp[MAX];
    int valid;
    printf("enter en valid expresssion");
    gets(exp);
    valid=check(exp);
    if(valid==1)
        printf("valid expression");
    else
        printf("invalid expression");
}
int check(char exp[])
{
    int i;
    char t;
    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            push(exp[i]);
      else  if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
            t=pop();
            match(t,exp[i]);
            if(match==1)
                printf("parentheses is valid");
            else
                printf("parentheses is not valid");
    }
}
void push(char item)
{
    if(top==MAX-1)
    {
        printf("it is overflow");
        return;
    }
    top=top+1;
    stack[top]=item;
}
char pop()
{
    if(top==-1)
    {
        printf("it is underflow");
        exit(1);
    }
    return(stack[top--]);

}
int match(char a,char b)
{
    if(a=='[' && b==']')
        return 1;
    if(a=='{' && b=='}')
        return 1;
    if(a=='('  && b==')')
        return 1;
    return 0;
}























