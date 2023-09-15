#include<stdio.h>
#include<conio.h>

void main()
{
    int a[20],i,j,temp;
    clrscr();

    printf("\nenter element in array : ");

    for(i=0;i<5;i++)
    {
	scanf("%d",&a[i]);
    }
    for(i=0;i<5;i++)
    {
	for(j=0;j<5-i-1;j++)
	{
		if(a[j]>a[j+1])
		{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
    }
    clrscr();
    printf("\nsorted data are :- ");
    for(i=0;i<5;i++)
	printf("\t%d",a[i]);
	getch();
}