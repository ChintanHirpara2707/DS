#include <stdio.h>
#include <stdlib.h>

struct linklist
{
	int info;
	struct linklist *next;
};

struct linklist *ins_beg(struct linklist *first, int y)
{
	struct linklist *temp;
	temp = (struct linklist *)malloc(sizeof(struct linklist));
	temp->next = NULL;
	temp->info = y;

	if (first == NULL)
			first = temp;
	else
	{
		temp->next = first;
		first = temp;
	}
	return first;
}

struct linklist *ins_end(struct linklist *first, int y)
{
	struct linklist *temp, *p;
	temp = (struct linklist *)malloc(sizeof(struct linklist));
	temp->next = NULL;
	temp->info = y;

	if (first == NULL)
		first = temp;
	else
	{
		p = first;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = temp;
	}
	return first;
}

struct linklist *ins_pos(struct linklist *first, int pos, int y)
{
	struct linklist *temp, *p, *q;
	int i = 1;
	temp = (struct linklist *)malloc(sizeof(struct linklist));
	temp->next = NULL;
	temp->info = y;

	if (pos == 1)
	{
		temp->next = first;
		first = temp;
	}
	else
	{
		p = first;
		while (i < pos - 1 && p != NULL)
		{
			p = p->next;
			i++;
		}
		if (p != NULL)
		{
			temp->next = p->next;
			p->next = temp;
		}
		else
		printf("Invalid position\n");
	}
	return first;
}

struct linklist *del_beg(struct linklist *first)
{
	struct linklist *p;

	if (first == NULL)
		printf("There is no node\n");
	else
	{
		p = first;
		printf("Deleted element is %d\n", p->info);
		first = first->next;
		free(p);
	}
	return first;
}

struct linklist *del_end(struct linklist *first)
{
	struct linklist *p, *q;

	if (first == NULL)
		printf("There is no node\n");
	else
	{
		p = first;
		if (p->next == NULL)
		{
			printf("Deleted element is %d\n", p->info);
			free(p);
			first = NULL;
		}
		else
		{
			while (p->next != NULL)
			{
				q = p;
				p = p->next;
			}
			printf("Deleted element is %d\n", p->info);
			q->next = NULL;
			free(p);
		}
	}
	return first;
}

struct linklist *del_pos(struct linklist *first, int pos)
{
	struct linklist *p, *q;
	int i = 1;

	if (pos == 1)
		first = del_beg(first);
	else
	{
		p = first;
		while (i < pos && p != NULL)
		{
			q = p;
			p = p->next;
			i++;
		}
		if (p != NULL)
		{
			q->next = p->next;
			printf("Deleted element is %d\n", p->info);
			free(p);
		}
		else
		printf("Invalid position\n");
	}
	return first;
}

void display(struct linklist *first)
{
	if (first == NULL)
	{
		printf("\nNo node\n");
	}
	else
	{
		struct linklist *p;
		p = first;
		printf("Data is: ");
		while (p != NULL)
		{
			printf("%d -> ", p->info);
			p = p->next;
		}
		printf("\n");
	}
}

int search(struct linklist *first, int x)
{
	int flag = 0;
	struct linklist *p;
	p = first;
	while (p != NULL)
	{
		if (p->info == x)
		{
			flag = 1;
			break;
		}
		else
		p = p->next;
	}
	return flag;
}

int count(struct linklist *first)
{
	int count = 0;
	struct linklist *p = first;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

struct linklist *copy(struct linklist *original)
{
	struct linklist *new_list = NULL;
	struct linklist *temp = original;

	while (temp != NULL)
	{
		new_list = ins_end(new_list, temp->info);
		temp = temp->next;
	}

	return new_list;
}

int main()
{
	struct linklist *first = NULL;
	int x, choice, pos;

	do
	{
		clrscr();

		printf("\n1. Insert at first");
		printf("\n2. Insert at last");
		printf("\n3. Insert at middle");
		printf("\n4. Delete at first");
		printf("\n5. Delete at last");
		printf("\n6. Delete at middle");
		printf("\n7. Count");
		printf("\n8. Search");
		printf("\n9. Copy ");
		printf("\n10. Display");
		printf("\n11. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
			{
				printf("Enter Value: ");
				scanf("%d", &x);
				first = ins_beg(first, x);
				break;
			}
			case 2:
			{
				printf("Enter Value: ");
				scanf("%d", &x);
				first = ins_end(first, x);
				break;
			}
			case 3:
			{
				printf("Enter position: ");
				scanf("%d", &pos);
				printf("Enter Value: ");
				scanf("%d", &x);
				first = ins_pos(first, pos, x);
				break;
			}
			case 4:
			{
				first = del_beg(first);
				break;
			 }
			case 5:
			{
				first = del_end(first);
				break;
			}
			case 6:
			{
				printf("Enter position: ");
				scanf("%d", &pos);
				first = del_pos(first, pos);
				break;
			}
			case 7:
			{
				printf("Number of nodes is %d\n", count(first));
				break;
			}
			case 8:
			{
				printf("Enter value to search: ");
				scanf("%d", &x);
				if (search(first, x))
				printf("Value is found\n");
				else
				printf("Value is not found\n");
				break;
			}
			case 9:

			{
				struct linklist *new_list = copy(first);
				printf("Copied list:\n");
				display(new_list);
				break;
			}
			case 10:
			{
				display(first);
				break;
			}
			case 11:
			exit(0);

		}


	getch();
	} while (1);

	return 0;
}