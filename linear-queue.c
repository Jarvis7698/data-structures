//	Implementation Of Linear Queue Using Array

#include<stdio.h>
#define size 5

int front=0;
int rear=0;
int i,j;
int q[size];

//	check if queue is full
int qisfull() {
	if(rear==size)
		return 1;
	else
		return 0;
}

//	check if queue is empty
int qisempty() {
	if(rear==0)
		return 1;
	else
		return 0;
}

//	enqueue
void enque() {
	if(!qisfull()) {
		int n;
		printf("\nEnter Data: ");
		scanf("%d", &n);
		q[rear] = n;
		rear += 1;
	}
	else {
		printf("\nSorry..Queue is Full!");
	}
}

//	dequeue
void deque() {
	if(!qisempty()) {
		printf("\nElement DeQueued Successfully!");
		for(i=0;i<rear;i++) {
			q[i] = q[i+1];
		}
		rear -= 1;
	}
	else {
		printf("\nQueue is Empty!");
	}
}

//	display the queue
void display() {
	printf("\nQueue Status: ");
	for(i=0;i<rear;i++) {
		printf("%d", q[i]);
	}
}

//	peek in queue
void peek() {
	printf("\nFront: %d", q[front]);
}

//search for something
void search() {
	int target,flag=0;
	printf("\nEnter Target Element: ");
	scanf("%d",&target);
	for(i=0;i&lt;rear;i++) {
		if(q[i] == target) {
			flag=1;
			break;
		}
	}
	if(flag==1)	{
		printf("\nElement Found!\nPosition = %d",i+1);
	}
	else {
		printf("\nElement Not Found..!!");
	}
}

//	update an element
void update() {
	int pos,data;
	printf("\nEnter Position: ");
	scanf("%d",&pos);
	if(pos > rear) {
		printf("\nEnter A Valid Position!");
	}
	else {
		printf("\nEnter New Data: ");
		scanf("%d", &data);
		q[pos-1] = data;
		printf("\nUpdation Completed!");
	}
}

//	sort the queue
void sort() {
	//My Sorting Technique
	int temp;
	for(i=rear-1;i>0;i--) {
		for(j=0;j<i;j++) {
			if(q[i] < q[j]) {
				temp = q[i];
				q[i] = q[j];
				q[j] = temp;
			}
		}
	}//Sorting Completed
	printf("\nSorting Completed!");
}

//main starts here
int main() {
	int choice;
	do {
		printf("\n----------------------------");
		printf("\n1. Enque\n2. Deque\n3. Display Queue\n4. Peek\n5. Search");
		printf("\n6. Update\n7. Sort\n8. Exit");
		printf("\n----------------------------");
		printf("\nEnter Your Choice: ");
		scanf("%d",&choice);
		switch(choice)	{
			case 1 : enque();break;
			case 2 : deque();break;
			case 3 : display();break;
			case 4 : peek();break;
			case 5 : search();break;
			case 6 : update();break;
			case 7 : sort();break;
			case 8 : printf("\nExiting...\n");break;
			default: printf("\nPlease Enter A Valid Choice!");
		}
	} while(choice!=8);
	return 0;
}
/*Program Ends Here*/
