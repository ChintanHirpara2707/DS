#include<stdio.h>
#include<stdlib.h>

struct clinklist
{
    int info;
    struct clinklist *next;
}*first, *last;

struct clinklist *ins_beg(struct clinklist *first, int y)
{
    struct clinklist *temp;
    temp = (struct clinklist *)malloc(sizeof(struct clinklist));
    temp->next = NULL;
    temp->info = y;

    if (first == NULL)
    {
        first = temp;
        last = temp;
        last->next = first;
    }
    else
    {
        temp->next = first;
        first = temp;
        last->next = first;
    }
    return first;
}

struct clinklist *ins_end(struct clinklist *first, int y)
{
    struct clinklist *temp;
    temp = (struct clinklist *)malloc(sizeof(struct clinklist));
    temp->next = NULL;
    temp->info = y;
    if (first == NULL)
    {
        first = temp;
        last = temp;
        last->next = first;
    }
    else
    {
        last->next = temp;
        last = temp;
        last->next = first;
    }
    return first;
}

struct clinklist *del_beg(struct clinklist *first)
{
    struct clinklist *p;
    if (first == NULL)
    {
        printf("\nThere is no node");
    }
    else if (first == last)
    {
        printf("\nDelete value is %d", first->info);
        free(first);
        first = last = NULL;
    }
    else
    {
        p = first;
        printf("\nDelete value is %d", p->info);
        first = first->next;
        last->next = first;
        free(p);
    }
    return first;
}

struct clinklist *del_end(struct clinklist *first)
{
    struct clinklist *p, *q;
    if (first == NULL)
    {
        printf("\nThere is no node");
    }
    else if (first == last)
    {
        printf("\nDelete value is %d", first->info);
        free(first);
        first = last = NULL;
    }
    else
    {
        p = first;
        while (p != last)
        {
            q = p;
            p = p->next;
        }
        printf("\nDelete value is %d", p->info);
        first = first->next;
        last->next = first;
        free(p);
    }
    return first;
}

void search(struct clinklist *first, int x)
{
    int flag = 0;
    struct clinklist *p;
    p = first;
    while (p != NULL)
    {
        if (p->info == x)
        {
            flag = 1;
            break;
        }
        else
            p = p->next;
    }
    if (flag == 1)
        printf("\nValue is found");
    else
        printf("\nValue is not found");
}

void display(struct clinklist *first)
{
    struct clinklist *p;
    if (first == NULL)
    {
        printf("\nNo node");
    }
    else if (first == last)
    {
        p = first;
        printf("\nData is: %d ->", p->info);
    }
    else
    {
        p = first;
        printf("\nData is: ");
        do
        {
            printf("%d ->", p->info);
            p = p->next;
        } while (p != first);
    }
}

int main()
{
    struct clinklist *first = NULL;
    int x = 0, choice;
    do
    {   clrscr();
	printf("\n1. Insert at first\n2. Insert at last\n3. Delete at first");
	printf("\n4. Delete at last\n5. Search\n6. Count\n7. Display\n8. Exit");
	printf("\nEnter your choice: ");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
	{
	    printf("\nEnter Value:");
	    scanf("%d", &x);
	    first = ins_beg(first, x);
	    break;
	}
	case 2:
	{
	    printf("\nEnter value");
	    scanf("%d", &x);
	    first = ins_end(first, x);
	    break;
	}
	case 3:
	{
	    first = del_beg(first);
	    break;
	}
	case 4:
	{
	    first = del_end(first);
	    break;
	}
	case 5:
	{
	    printf("\nEnter value to search:");
	    scanf("%d", &x);
	    search(first, x);
	    break;
	}
	case 6:
	{
	    int count = 0;
	    struct clinklist *p = first;
	    do
	    {
		count++;
		p = p->next;
	    } while (p != first);
	    printf("Number of nodes is %d", count);
	    break;
	}
	case 7:
	{
	    display(first);
	    break;
	}

	case 8:
	{
	    exit(0);
	}
	}
	getch();
    } while (1);

    return 0;
}
