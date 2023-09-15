#include<stdio.h>
#include<conio.h>
void input(int a[20],int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		printf("\nEnter number:");
		scanf("%d",&a[i]);
	}
}
void display(int a[20],int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}

void sort(int a[20],int lb,int ub,int n)
{
	int flag=1,i,j,key,t;
	static int c=1;
	if(lb<ub)
	{
		i=lb;
		j=ub+1;
		key=a[lb];

		while(flag==1)
		{
			i=i+1;
			while(a[i]<key)
			{
				i=i+1;
			}
			j=j-1;
			while(a[j]>key)
			{
				j=j-1;
			}
			if(i<j)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
			else
			{
				flag=0;
			}
		}
		t=a[lb];
		a[lb]=a[j];
		a[j]=t;
			printf("\npass-%d\t",c);
			c++;
		display(a,n);

		sort(a,lb,j-1,n);
		sort(a,j+1,ub,n);

	}
}
void main()
{
	int a[20],n,lb,ub;
	clrscr();
	printf("\nenter number of element to enter: ");
	scanf("%d",&n);
	lb=0;
	ub=n-1;

	input(a,n);
	display(a,n);

	sort(a,lb,ub,n);
	getch();
}