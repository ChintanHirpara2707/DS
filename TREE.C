#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
struct treenode
{
    struct treenode *lchild;
    int data;
    struct treenode *rchild;
};
struct treenode *insert(struct treenode *root,int d)
{
    struct treenode *p,*q;
    struct treenode *temp;
    int flag=0;
    temp=(struct treenode *)malloc(sizeof(struct treenode));
    temp->lchild=NULL;
    temp->rchild=NULL;
    temp->data=d;

     if(root==NULL)
     {
        root=temp;
     }
     else
     {
        p=root;

        while((p!=NULL)&&(flag==0))
        {
            if(d<p->data)
            {
                q=p;
                p=p->lchild;
	    }
	    else if(d>p->data)
	    {
		q=p;
		p=p->rchild;
	    }
            else if(p->data==d)
            {
                flag=1;
                printf("\nitem Already Exist");
            }
        }
        if(p==NULL)
        {
            if(d>q->data)
            {
                q->rchild=temp;
            }
            else
            {
                q->lchild=temp;
            }
        }
    }
     return root;
}

void inorder(struct treenode *root)
{
    struct treenode*t;
    t=root;
    if(t!=NULL)
    {
	inorder(t->lchild);
	printf("%d:",t->data);
	inorder(t->rchild);
    }
}

void preorder(struct treenode *root)
{

    struct treenode*t;
    t=root;
    if(t!=NULL)
    {
	printf("%d:",t->data);
	preorder(t->lchild);
	preorder(t->rchild);
    }
}

void postorder(struct treenode *root)
{
    struct treenode*t;
    t=root;
    if(t!=NULL)
    {
	postorder(t->lchild);
	postorder(t->rchild);
	printf("%d:",t->data);
    }
}

void main()
{
    struct treenode *root=NULL;
    int inp=1,d,delno;
    clrscr();

    while(inp<=5)
    {
	clrscr();
	printf("\n1.insert");
	printf("\n2.Display inorder");
	printf("\n3.Display preorder");
	printf("\n4.Display postorder");
	printf("\n5.exit");

	printf("\nSelect option:");
	scanf("%d",&inp);

	switch(inp)
	{
	    case 1:
	    {
		printf("\nEnter The Data:-");
		scanf("%d",&d);
		root=insert(root,d);
		break;
	    }

	     case 2:
	    {
		inorder(root);
		break;
	    }

	     case 3:
	    {
		preorder(root);
		break;
	    }

	     case 4:
	    {
		postorder(root);
		break;
	    }

	    case 5:
	    {
		exit(0);
	    }
	}
	getch();
    }
    getch();
}