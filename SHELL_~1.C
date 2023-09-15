//shell sort
#include <stdio.h>
#include <conio.h>

void main()
{
    int a[20], i, j,key=0,n;
    int t = 0,swap = 0,c = 1,gap;
    clrscr();

    printf("\nEnter number of element to enter:");
    scanf("%d",&n);

    for (i = 0; i <10 ; i++)
    {
	printf("\nEnter Number:");
	    scanf("%d", &a[i]);
    }
    gap=n/2;
    do
    {
	do
	{
		swap=0;
		for(i=0;i<n-gap;i++)
		{
			if(a[i]>a[i+gap])
			{
				t=a[i];
				a[i]=a[i+gap];
				a[i+gap]=t;
				swap=1;
			}
		 }
		 if(swap==1)
		 {
			printf("\nPASS-%d\t",c);
			c=c+1;
			for(i=0;i<n;i++)
			{
				printf("%d",a[i]);
			}
		 }
	}while(swap==1);
    }while(gap=gap/2);
    clrscr();
    printf("\nSorted Data are:");
    for (i = 0; i <10; i++)
    {
	printf("\t%d",a[i]);
    }
    getch();
}