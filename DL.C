#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct dlinklist
{
    int info;
    struct dlinklist *next, *prv;
} *first, *last;

struct dlinklist *ins_beg(struct dlinklist *first, int y)
{
    struct dlinklist *temp;
    temp = (struct dlinklist *)malloc(sizeof(struct dlinklist));
    temp->next = NULL;
    temp->prv = NULL;
    temp->info = y;

    if (first == NULL)
    {
        first = temp;
        last = temp;
    }
    else
    {
        temp->next = first;
        first->prv = temp;
        first = temp;
    }
    return first;
}

struct dlinklist *ins_end(struct dlinklist *first, int y)
{
    struct dlinklist *temp, *p;
    temp = (struct dlinklist *)malloc(sizeof(struct dlinklist));
    temp->next = NULL;
    temp->prv = NULL;
    temp->info = y;
    if (first == NULL)
    {
        first = temp;
        last = temp;
    }
    else
    {
        p = last;
        p->next = temp;
        temp->prv = p;
        last = temp;
    }
    return first;
}

struct dlinklist *del_beg(struct dlinklist *first)
{
    struct dlinklist *p, *temp;
    if (first == NULL)
    {
        printf("\nThere is no node");
    }
    else
    {
        p = first;
        printf("\nDelete value is %d", p->info);
        first = first->next;
        if (first != NULL)
        {
            first->prv = NULL;
        }
        free(p);
    }
    return first;
}

struct dlinklist *del_end(struct dlinklist *first)
{
    struct dlinklist *p, *temp;
    if (first == NULL)
    {
        printf("\nThere is no node");
    }
    else if (first->next == NULL)
    {
        printf("\nDelete value is %d", first->info);
        free(first);
        first = last = NULL;
    }
    else
    {
        p = last;
        printf("\nDelete value is %d", p->info);
        last = last->prv;
        last->next = NULL;
        free(p);
    }
    return first;
}

void search(struct dlinklist *first, int x)
{
    int flag = 0;
    struct dlinklist *p;
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

void display(struct dlinklist *first)
{
    struct dlinklist *p;
    if (first == NULL)
    {
        printf("\nNo node");
    }
    else
    {
        p = first;
        printf("\nData is: ");
        while (p != NULL)
        {
            printf("%d ->", p->info);
            p = p->next;
        }
    }
}

int main()
{
    struct dlinklist *first = NULL;
    int x = 0, choice;
    do
    {
        clrscr();

        printf("\n1. Insert at first\n2. Insert at last\n3. Delete at first");
        printf("\n4. Delete at last");
        printf("\n5. Search\n6. Count\n7. Display\n8. Exit");
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
            struct dlinklist *p = first;
            while (p != NULL)
            {
                count++;
                p = p->next;
            }
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
