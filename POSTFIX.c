#include <stdio.h>
#include <conio.h>
#define size 20

int top=-1;

void push(char *s, char x)
{
	if(top==(size-1))
	{
		printf("\nStack Is Full");
	}
	else
	{
		top++;
		s[top]=x;
	}
}

char pop(char *s)
{
	char x;

	x=s[top];
	top--;
	return x;
}

int icp(char x)
{
	int p;
	switch(x)
	{
		case '+':
		case '-':
			p=1;
			break;
		case '*':
		case '/':
			p=3;
			break;
		case '^':
			p=6;
			break;
	}
	return p;
}

int isp(char x)
{
	int p;
	switch(x)
	{
		case '+':
		case '-':
			p=2;
			break;
		case '*':
		case '/':
			p=4;
			break;
		case '^':
			p=5;
			break;
		case '(':
			p=0;
			break;
	}
	return p;
}

void intopost(char *s, char infix[20], char postfix[20])
{
	int i=0,len,k=0;
	char x;
	strcat(infix,")");
	len=strlen(infix);
	push(s,'(');

	while(i<len)
	{
		if(infix[i]=='(')
		{
			push(s,infix[i]);
			i++;
		}
		else if(infix[i]==')')
		{
			while((x=pop(s))!='(' && top!=-1)
			{
				postfix[k]=x;
				k++;
			}
			i++;
		}
		else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='^')
		{
			while((icp(infix[i]))<=(isp(s[top])))
			{
				x=pop(s);
				postfix[k]=x;
				k++;
			}
			push(s,infix[i]);
			i++;
		}
		else
		{
			postfix[k]=infix[i];
			k++;
			i++;
		}
	}
	postfix[k]='\0';
}

void main()
{
	char *s,infix[20],postfix[20];
	s=(char *)malloc(size * sizeof(char));
	clrscr();

	printf("\nEnter The Infix Expression :");
	gets(infix);

	intopost(s,infix,postfix);

	printf("\nThe Postfix Expression Is :\n");
	puts(postfix);

	getch();
}