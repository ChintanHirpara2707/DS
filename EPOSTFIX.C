#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int top=-1;
double s[100];

void push(double val)
{
	top++;
	s[top]=val;
}

double pop()
{
	return s[top--];
}

double post(char exp[])
{
	char ch,*t;
	double result,val,op1,op2;
	int i=0;
	while(ch!='\0')
	{
		ch=exp[i];
		if(ch>='0'&& ch<='9')
		{
			val=ch-48;
			push(val);
		}
		else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
		{
			op2=pop();
			op1=pop();
			switch(ch)
			{
				case '+':
				{
					result=op1+op2;
					break;
				}
				case '-':
				{
					result=op1-op2;
					break;
				}
				case '*':
				{
					result=op1*op2;
					break;
				}
				case '/':
				{
					result=op1/op2;
					break;
				}
				case '^':
				{
					result=pow(op1,op2);
					break;
				}
			}
			push(result);
		}
		i++;

	}
	return result;
}

void main()
{
	char exp[100];
	double result;
	clrscr();
	printf("Enter String : ");
	scanf("%s",exp);
	result=post(exp);
	printf("\nAnswer is %lf",result);
	getch();
}