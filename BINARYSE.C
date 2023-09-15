#include<stdio.h>
#include<conio.h>

void main()
{
    int a[20],i,x,flag=0,low,high,mid;
    clrscr();

    printf("\nenter element array : ");

    for(i=0;i<5;i++)
    {
	scanf("%d",a[i]);
    }

    printf("\nenter search number : ");
    scanf("%d",&x);

    low=0,high=4;
    while(low<=high)
    {
	mid=(low+high)/2;

	if(a[mid]==x)
	{
		flag=1;
		break;
	}
	else if(x<a[mid])
		high=mid-1;
	else
		low=mid+1;
    }
    if(flag==1)
	printf("\nvalue is not found");
    else
	 printf("\nvalue is found");
    getch();
}