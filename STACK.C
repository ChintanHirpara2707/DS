#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define n 5

void main()
{
    int s[5], top = -1, x, choice, i, p;

    do
    {
	clrscr();
	printf("\n1.push\n2.pop\n3.update\n4.peep\n5.display\n6.exit");
	printf("\nEnter your Choice:");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
	{
	    printf("\nEnter value:");
	    scanf("%d", &x);
	    if (top >= n - 1)
		printf("\nStack is Full");
	    else
	    {
		top++;
		s[top] = x;
	    }
	    break;
	}
	case 2:
	{
	    if (top == -1)
		printf("\nStack is Empty");
	    else
	    {
		printf("\nDeleted value is %d", s[top]);
		top--;
	    }
	    getch();
	    break;
	}
	case 3:
	{
	    printf("\nEnter index no:");
	    scanf("%d", &p);

	    printf("\nEnter a value:");
	    scanf("%d", &x);


	    if (p > top)
		printf("\nInvalid index! Data is not available.");
	    else
	    {
		s[p] = x;
	    }
	    break;
	}
	case 4:
	{
	    printf("\nEnter index no: ");
	    scanf("%d", &p);

	    if (p < 0 || p > top)
	    {
		printf("\nInvalid index! The stack has elements from index 0 to %d.", top);
	    }
	    else
	    {
		clrscr();
                printf("\nValue at index %d is %d", p, s[p]);
                getch();
            }
            break;
        }
        case 5:
        {
            if (top == -1)
                printf("\nStack is Empty");
            else
            {
                clrscr();
                printf("\nStack Elements are:");
                for (i = 0; i <= top; i++)
                    printf("%d\t", s[i]);
                getch();
            }
            break;
        }
        case 6:
            exit(0);
        }
    } while (1);
    getch();
}
