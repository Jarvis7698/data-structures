// C program to demonstrate working of a Stack;

#include<stdio.h>
#define size 100

// stack and stack top declaration;
int stack[size];
int top = -1;

// check if stack is full;
int stackFull() {
	if(top >= size) return 1;
	return 0;
}

// check if stack is empty;
int stackEmpty() {
	if(top < 0) return 1;
	return 0;
}

// Push something into the stack;
void push() {
	if(!stackFull()) {
		int data;
		printf("\nEnter value to be pushed: ");
		scanf("%d", &data);
		top += 1;
		stack[top] = data;
		printf("\n%d Pushed succesfully!\n",data);
	} else {
		printf("\nStack OverFlow!\n");
	}
}

// Pop the stack top out;
void pop() {
	if(!stackEmpty()) {
		int popped = stack[top];
		top -= 1;
		printf("\n%d Popped succesfully!\n",popped);
	} else {
		printf("\nStack UnderFlow!\n");
	}
}

// Show the stack top;
void peek() {
	if(!stackEmpty()) {
		printf("\nStack Top: %d\n", stack[top]);
	} else {
		printf("\nStack is empty!\n");
	}
}

// Display all the contents of stack;
void display() {
	int i;
	if(!stackEmpty()) {
		printf("\nStack: ");
		for(i=0; i<=top; i++) {
			printf("%d ",stack[i]);
		}
		printf("\n");
	} else {
		printf("\nStack is empty!\n");
	}
}

int main() {
	int choice;
	do {
		/* User Menu */
		printf("\n1. Push\n2. Pop\n3. Peek\n4. Show Stack\n5. Exit\n");
		printf("\nEnter Choice: ");
		scanf("%d", &choice);
		
		/* Switch to user's choice */
		switch(choice) {
			case 1: push();break;
			case 2: pop();break;
			case 3: peek();break;
			case 4: display();break;
			case 5: printf("\nExiting..");break;
			default:printf("\nInvalid Option!\n");
		}
	} while(choice!=5);
}
/* Program Ends Here */
