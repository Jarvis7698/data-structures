#include<stdio.h>
#define size 5

int arr[size];
int top=0;
void stackPush();
void stackPop();
int stackIsEmpty();
int stackIsFull();
void stackDisplay();

void stackPush()
{
	int check = stackIsFull();
	if(check == 1)
	{
		printf("\nEnter Element: ");
		scanf("%d",&arr[top]);
		top++;
	}
	else
		printf("\n STACK OVERFLOW! ");
}

void stackPop()
{
	int check = stackIsEmpty();
	if(check == 1)
	{	
		top--;
		printf("\nPopped Element %d\n",arr[top]);
		
	}
}

int stackIsEmpty()
{
	int i=0;
	if(top>0)
	{
		i=1; 		
	}
	else
	{
		printf("\n STACK UNDERFLOW!");
	}
	return i;
}

void stackDisplay()
{
	int i;
	printf("\nCurrent Status Of Stack: ");
	for(i=0;i<top;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int stackIsFull()
{
	int i=0;
	if(top<=size-1)
	{
		i=1; 
	}
	return i;
}

void main()
{
	int choice;
	do
	{
		printf("\n----------------------------------------------\n");
		printf("\n1.Push\n2.Pop\n3.Display Stack\n4.Exit\n");
		printf("\nEnter Your Choice: \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :stackPush();break;
			case 2 :stackPop();break;
			case 3 :stackDisplay();break;
			case 4 :printf("\nExiting Stack...!!\n");break;
			default:printf("\nEnter Valid Choice!");
		}
	}while(choice!=4);
	
}
/*Program Ends Here*/


