/*
**	Doubly Linked-List Implementation
*/

#include<stdio.h>
#include<stdlib.h>

struct family {
	struct family * prev;
	int data;
	struct family * next;
};

/*	FC - Fist Child
**	YS - Youngest Son
**	OS - Oldest Son 
*/

struct family * fc, * ys, * os, * introducer;

int len = 0,flag = 0;
void create();
void display();
void insbeg();
void insmid();
void insend();
void delbeg();
void delmid();
void delend();
void search();
void update();
void revrse();

int main() {
	int choice;
	do {
		printf("\n-----------------------------------------------\n");
		printf("\n 1. Create");
		printf("\n 2. Display\n");
		printf("\n 3. Insert A Node At Beginning");
		printf("\n 4. Insert A Node In Middle");
		printf("\n 5. Insert A Node At End\n");
		printf("\n 6. Delete A Node From Beginning");
		printf("\n 7. Delete A Node From Middle");
		printf("\n 8. Delete A Node From End\n");
		printf("\n 9. Search");
		printf("\n10. Update");
		printf("\n11. Reverse\n");
		printf("\n12. Exit\n");
		printf("\n>>>>Enter Choice: ");
		scanf("%d",&choice);
		printf("\n-----------------------------------------------\n");
		switch(choice) {
			case 1 : create();break;
			case 2 : display();break;
			case 3 : insbeg();break;
			case 4 : insmid();break;
			case 5 : insend();break;
			case 6 : delbeg();break;
			case 7 : delmid();break;
			case 8 : delend();break;
			case 9 : search();break;
			case 10: update();break;
			case 11: revrse();break;
			case 12: break;
			default: printf("\nEnter A Valid Option!\n");
		}
	}while(choice!=12);
	
	printf("\nLength = %d",len);
	printf("\nfc= %d\nos= %d",fc->data,os->data);
	
	system("pause");
	return 0;
}

/*Create A Doubly Linked List */
void create() {
	if(flag==1) {
		printf("\nDoubly Linked-List Already Exists!\n");
	} else {
		int num;
		fc = NULL;
		printf("\nEnter 0 to Stop!\n");
		printf("\nEnter Data: ");
		scanf("%d",&num);
		while(num!=0) {
			ys = (struct family*)malloc(sizeof(struct family));
			ys->data = num;
		
			if(fc == NULL) {
				fc = ys;
				os = ys;
				flag = 1;
			} else {
				os->next = ys;
				ys->prev = os;
				os = ys;
			}
			printf("\nEnter Data: ");
			scanf("%d",&num);
			len++;
		}
		fc->prev = NULL;
		os->next = NULL;
		if(flag==0)	{
			printf("\nPlease Create A Doubly Linked-List First!\n");
		} else {
			printf("\nDoubly Linked-List Created Successfully!\n");
		}
	}
}

/*Display Linked List */
void display() {
	if(flag==0)	{
		printf("\nPlease Create A Doubly Linked-List First!\n");
	} else {
		introducer = fc;
		printf("\nForward Linked-List:  ");
		while(introducer!=NULL)	{
			printf("%d ",introducer->data);
			introducer = introducer->next;
		}
		printf("\n");
		
		introducer = os;
		printf("\nBackward Linked-List: ");
		while(introducer!=NULL)	{
			printf("%d ",introducer->data);
			introducer = introducer->prev;
		}
		printf("\n");
	}
}

/*Insert Node In Start */
void insbeg() {
	if(flag==0)	{
		printf("\nPlease Create A Doubly Linked-List First!\n");
	} else {
		printf("\nEnter Data: ");
		ys = (struct family *)malloc(sizeof(struct family));
		scanf("%d",&ys->data);
		ys->prev = NULL;
		ys->next = fc;
		fc->prev = ys;
		fc = fc->prev;
		len++;
		printf("\nNode Added Successfully!\n");
	}
}

/*Insert Node In Middle */
void insmid() {
	if(flag==0)	{
		printf("\nPlease Create A Doubly Linked-List First!\n");
	} else {
		struct family * backup;
		introducer = fc;
		int pos,count = 1;
		ys = (struct family *)malloc(sizeof(struct family));
		printf("\nEnter Position: ");
		scanf("%d",&pos);
		if(pos<2 || pos>len) {
			printf("\nInvalid Position!");
		} else {
			while(count<pos) {
				introducer = introducer->next;
				count++;
			}
			backup = introducer->prev;
			printf("\nEnter Data: ");
			scanf("%d",&ys->data);
			ys->prev = introducer->prev;
			ys->next = backup->next;
			backup->next = ys;
			introducer->prev = ys;
			len++;
			printf("\nNode Added Successfully!\n");
		}
	}
}

/*Insert A Node In The End */
void insend() {
	if(flag==0)	{
		printf("\nPlease Create A Doubly Linked-List First!\n");
	} else {
		ys = (struct family *)malloc(sizeof(struct family));
		printf("\nEnter Data: ");
		scanf("%d",&ys->data);
		ys->next = NULL;
		ys->prev = os;
		os->next = ys;
		os = ys;
		len++;
		printf("\nNode Added Successfully!\n");
	}
}

/*Delete A Node From Beginning */
void delbeg() {
	if(flag==0)	{
		printf("\nPlease Create A Doubly Linked-List First!\n");
	} else {
		if(len<=2) {
			printf("\nCannot Delete More!\n");
		} else {
			introducer = fc;
			fc = fc->next;
			fc->prev = NULL;
			free(introducer);
			len--;
			printf("\nNode Deleted Successfully!\n");
		}
	}
}

/*Delete A Node from Middle */
void delmid() {
	if(flag==0) {
		printf("\nPlease Create A Doubly Linked-List First!\n");
	} else {
		if(len<=2) {
			printf("\nCannot Delete More!\n");
		} else {
			int pos,count=1;
			printf("\nEnter Position: ");
			scanf("%d",&pos);
			if(pos>=len || pos<=1) {
				printf("\nInvalid Position!\n");
			} else {
				struct family * pre, * post;
				introducer = fc;
				while(count<pos) {
					introducer = introducer->next;
					count++;
				}
				pre = introducer->prev;
				post= introducer->next;
				pre->next = post;
				post->prev = pre;
				free(introducer);
				len--;
				printf("\nNode Deleted Successfully!\n");
			}
		}
	}
}

/*Delete Node From End */
void delend() {
	if(flag==0)	{
		printf("\nPlease Create A Doubly Linked-List First!\n");
	} else {
		if(len<=2) {
			printf("\nCannot Delete More!\n");
		} else {
			introducer = os;
			os = os->prev;
			os->next = NULL;
			free(introducer);
			len--;
			printf("\nNode Deleted Successfully!\n");
		}
	}
}

/*Search A Node With User Given Data */
void search() {
	if(flag==0)	{
		printf("\nPlease Create A Doubly Linked-List First!\n");
	} else {
		int target,flg=0,pos=1;
		introducer = fc;
		printf("\nEnter Target Element: ");
		scanf("%d",&target);
		while(introducer!=NULL) {
			if(introducer->data == target) {
				flg=1;
				break;
			} else {
				introducer = introducer->next;
				pos++;
			}
		}
		if(flg==0) {
			printf("\nElement Not Found!\n");
		} else {
			printf("\nElement Found At Position %d!\n",pos);
		}
	}
}

/*Update A Node */
void update() {
	if(flag==0)	{
		printf("\nPlease Create A Doubly Linked-List First!\n");
	} else {
		int pos,count=1;
		printf("\nEnter Position: ");
		scanf("%d",&pos);
		if(pos<=0 || pos>len) {
			printf("\nInvalid Position!\n");
		} else {
			introducer = fc;
			while(count<pos) {
				introducer = introducer->next;
				count++;
			}
			printf("\nEnter New Data: ");
			scanf("%d",&introducer->data);
			printf("\nNode Updated Successfully!\n");
		}
	}
}

/*Reverse The Doubly Linked List */
void revrse() {
	if(flag==0)	{
		printf("\nPlease Create A Doubly Linked-List First!\n");
	} else {
		introducer = fc;
		struct family * temp = NULL;
		while(introducer!=NULL) {
			temp = introducer->next;
			introducer->next = introducer->prev;
			introducer->prev = temp;
			introducer = introducer->prev;
		}
		temp = fc;
		fc = os;
		os = temp;
		printf("\nDoubly Linked-List Reversed Successfully!\n");
	}
}

/*Program Ends Here */












