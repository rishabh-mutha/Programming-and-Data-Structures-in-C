#include<stdio.h>
int stack[100];
int top = -1;
 
void push(int x)
{
        stack[++top] = x;
}
 
int pop()
{
        return stack[top--];
}
 
void main()
{
        char exp[100];
        char *e;
        int n1,n2,n3,x;
        printf("Enter the postfix expression: ");
        scanf("%s",exp);
        e = exp;
        while(*e != '\0')
        {
                if(*e>='0' && *e<='9')
                {
                        x = *e - 48;
                        push(x);
                }
                else
                {
                        n1 = pop();
                        n2 = pop();
                        switch(*e)
                        {
                                case '+':
                                {
                                        n3 = n1 + n2;
                    			break;
                                }
                                case '-':
                                {
                                        n3 = n2 - n1;
                                        break;
                                }
                                case '*':
                                {
                                        n3 = n1 * n2;
                                        break;
                                }
                                case '/':
                                {
                                        n3 = n2 / n1;
                                        break;
                                }
                        }
                        push(n3);
                }
                e++;
        }
        printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
    
 
}
