#include <stdio.h>
#include <conio.h>
#include <malloc.h>


struct linklist
{
    int info;
    struct linklist *next;
};


struct linklist * ins_ord(struct linklist *first,int x)
{
    struct linklist *temp,*p,*q;

    temp=(struct linklist *)malloc(sizeof(struct linklist));
    temp->next=NULL;
    temp->info=x;

    if(first==NULL || x<first->info)
    {
	    temp->next=first;
	    first=temp;
    }

    else
    {
	    p=first;
	    while(p!=NULL && x>p->info)
	    {
		q=p;
		p=p->next;
	    }
	    q->next=temp;
	   temp->next=p;
    }
    return first;
}

void display(struct linklist * first)
{

    if(first==NULL)
    {
    printf("\nNo node");
    }
    else
    {
	struct linklist *p;
	p=first;
	while(p!=NULL)
	{
		printf("%d -> ", p->info);
		p=p->next;
	}
    }

}


void main()
{
    int x,choice=0;
    struct linklist *first=NULL;
    do
    {
	clrscr();
	printf("Enter value");
	scanf("%d",&x);

	first=ins_ord(first,x);
	display(first);
	    getch();

	printf("\npress 1 for continue \n press 0 for exit");
	scanf("%d",&choice);

    } while(choice==1);
}
