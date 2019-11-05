// C program to demonstrate Linked-List;

#include<stdio.h>
#include<stdlib.h>

// define the structure of a node;
struct node {
	int data;
	struct node *next;
};

// Linked-List required variables;
int exists = 0;
struct node *start = NULL, *end, *born, *ptr, *follow;


//	returns a newly created node in the memory;
struct node * get_new_node(int data) {
	// syntax: <var_type>* <var_name> = (<var_type>*)malloc(sizeof(<var_type>));
	struct node * new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

// Initially create a linked-list to begin with;
void create_list() {
	int i, n, temp;
	printf("\nEnter Number of Elements: ");
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		printf("node[%d]: ",i+1);
		scanf("%d", &temp);
		born = get_new_node(temp);
		if(start == NULL) {
			// if no root node exists, 
			// this will create a start root node;
			start = born;
			end = born;
		}
		else {
			// if a root node is created earlier, 
			// append new nodes ahead;
			end->next = born;
			end = born;
		}
	}
	exists = 1;
	printf("\nList Created Succesfully!\n");
}

// allows user to add a new node at the end of the list;
void add_node() {
	int data;
	printf("\nEnter Data: ");
	scanf("%d", &data);
	// get a new fresh node with user provided data;
	born = get_new_node(data);
	// append the fresh node at the end;
	end->next = born;
	end = born;
	printf("\nAdded Succesfully!\n");
}

// allows user to delete any data node within the list, if exists;
void delete_node() {
	int target, found = 0;
	printf("\nEnter Target to delete: ");
	scanf("%d", &target);
	// traverse through the list looking for target data;
	ptr = start;
	while(ptr != NULL) {
		if(ptr->data == target) {
			// if a match is found, stop looking ahead;
			found = 1;
			break;
		}
		// let a follow pointer track the previous visited node;
		// while deleting, this will help us to maintain a link with previous node; 
		follow = ptr;
		ptr = ptr->next;
	}
	if(!found) {
		printf("\nTarget not found!\n");
		system("pause");
	} else {
		// if target is found inside the list;
		if(ptr == start) {
			// check if the start node is being deleted;
			// in such cases, simply make the next node as the root node;
			start = ptr->next;
			// free the start node now;
			free(ptr);
		}
		else {
			// if target node is any node within the list, perform deleteion;
			// link up the previous node's address section to the target's next node; 
			follow->next = ptr->next;
			// free up the target node now;
			free(ptr);
		}
	}
	printf("\nDeleted Succesfully!\n");
}

// show content of the linked-list;
void print_list() {
	ptr = start;
	printf("\nLinked List: ");
	while(ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
	system("pause");
}

// MAIN starts here;
int main() {
	int choice;
	do {
		/* USER MENU */
		system("cls");
		printf("\n*****LINKED-LIST*****\n");
		printf("\n1. Create List\n2. Add Node\n3. Delete Node\n4. Show List\n5. Exit");
		printf("\nEnter Choice: ");
		scanf("%d", &choice);
		
		/* Switch to user's choice */
		switch(choice){
			case 1: if(!exists) create_list();
					else printf("\nAlread Exists!\n");
					break;
			case 2: if(exists) add_node();
					else printf("\nCreate A List Please!\n");
					break;
			case 3: if(exists) delete_node();
					else printf("\nCreate A List Please!\n");
					break;
			case 4: if(exists) print_list();
					else printf("\nCreate A List Please!\n");
					break;
			case 5: printf("\nExiting...");
					break;
			default:printf("\nInvalid Choice!\n");system("pause");
		}
	} while(choice!=5);
	return 0;
}
