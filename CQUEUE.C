#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define n 10

int main() {
    int q[10], f, r, x, i, choice;
    f = r = -1;

    do {
		clrscr();
		printf("\n1.insert\n2.delete\n3.display\n4.exit");
		printf("\nenter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		      case 1:
		      {
			if((f==0 && r==(n-1)) || (f==r+1))
			printf("\nqueue is full");
			else
			{
				printf("\nenter value: ");
				scanf("%d", &x);
				if (r==(n-1))
				r = 0;
				else
				r = r + 1;
				if(f==-1)
				f=0;
				q[r] = x;
			}
			break;
		      }
			case 2:
			{
				int y;
				if (f == -1)
				printf("\nqueue is empty");
				else
				{
					printf("\n%d is deleted value", q[f]);
					if (f==r)
					f = r = -1;
					else if(f==(n-1))
					f=0;
					else
					f=f+1;
				}
				break;
			}
			case 3:
			{
			    int i=0;
			    if (f == -1 && r == -1)
			    printf("\nqueue is empty");
			    else
			    {
				i = f;
				printf("\nqueue data are: ");
				while (i <= r)
			    {
				printf("%d\t", q[i]);
				 i = i + 1;
			    }
			}
			break;
			}
			case 4:
			{
				exit(0);
			}
		}
		getch();
		} while (1);

    return 0;
}