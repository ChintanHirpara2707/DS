#include<stdio.h>
#include<conio.h>

void main()
{
    int a[20],i,x,flag=0;
    clrscr();

    printf("\nenter element array : ");

    for(i=0;i<5;i++)
    {
        scanf("%d",a[i]);
    }

    printf("\nenter search number : ");
    scanf("%d",&x);

    for(i=0;i<5;i++)
    {
        if(a[i]==x)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
	printf("\nvalue is not found");
    else
	 printf("\nvalue is found");
    getch();       
}