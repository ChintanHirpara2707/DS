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
	for(j=i+1;j<5;j++)
	{
		if(a[i]>a[j])
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
    }
    clrscr();
    printf("\nselection data are :- ");
    for(i=0;i<5;i++)
	printf("\t%d",a[i]);
	getch();
}