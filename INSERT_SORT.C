#include <stdio.h>
#include <conio.h>

void main()
{
    int a[20], i, j,key=0,n;
    clrscr();

    printf("\nEnter Element Array:");
    scanf("%d",&n);

    for (i = 0; i < 5; i++)
    {
        printf("\nEnter Number:");
	    scanf("%d", &a[i]);
    }

	for(i=1;i<n;i++)
    {    
            key=a[i];
            j=i-1;
            while(j>=0 && a[j]>=key)
            {
                a[j+1]=a[j];
                j=j-1;
            }
            a[j+1]=key;
    }   
    clrscr();
    printf("\nSorted Data are:");
    for (i = 0; i < 5; i++)
    {
        printf("\t%d",a[i]);
    }
    getch();
}