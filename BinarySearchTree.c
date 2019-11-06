#include<stdio.h>
#include<stdlib.h>

struct BST {
	int data;
	struct BST * left, * right;
};

struct BST * root, * temp;
int chkcreate = 0,searchflag = 0;
int findmin(struct BST *);

struct BST * GetNew(int data) {
	struct BST * newNode = (struct BST *)malloc(sizeof(struct BST));
	newNode->left = newNode->right = NULL;
	newNode->data = data;
	return newNode ;
}

struct BST * insert (struct BST * root, int data) {
	if(root == NULL) {
		root = GetNew(data);
	}
	else if(data <= root->data) {
		root->left = insert(root->left,data);
	}
	else {
		root->right = insert(root->right,data);
	}
	return root;
}

void postorder(struct BST * root) {
	if(root == NULL) 
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
	
}

void inorder(struct BST * root) {
	if(root == NULL) 
		return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
		
}

void preorder(struct BST * root) {
	if(root == NULL) 
		return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);	
}

void create() {
	if(!chkcreate) {
		int num;
		printf("Enter Data: ");
		scanf("%d",&num);
		while(num!=0) {
			root = insert(root,num);
			printf("Enter Data: ");
			scanf("%d",&num);
		}	
		printf("\nBST Created Successfully!\n");
		chkcreate = 1;
	}
	else {
		printf("\nAlready Created!\n");
	}
}

void display() {
	printf("\n\n PreOrder Traversal : ");
	preorder(root);
	printf("\n\n  InOrder Traversal : ");
	inorder(root);
	printf("\n\nPostOrder Traversal : ");
	postorder(root);	
	printf("\n");
}

void insnew() {
	int num;
	printf("Enter Data: ");
	scanf("%d",&num);
	root = insert(root,num);
}

struct BST * BSTsearch(struct BST * root, int data) {
	if(root == NULL) return root;
	if(root->data == data)	
		searchflag = 1;
	else if(data <= root->data)	
		root->left = BSTsearch(root->left, data);
	else 
		root->right = BSTsearch(root->right, data);
	return root;
}

void search() {
	int target;
	printf("\nEnter Target Element: ");
	scanf("%d",&target);
	temp = BSTsearch(root,target);
	(searchflag)?printf("\nElement Found!\n"):printf("\nElement Not Found!\n");
	searchflag = 0;
}

struct BST * deletethis(struct BST * root, int data) {
	if(root == NULL) return root;
	else if(data <= root->data) root->left = deletethis(root->left, data);
	else if(data > root->data) root->right = deletethis(root->right, data);
	else {/*Node To Be Deleted Found*/
		
		/*Case 1: Leaf Node Deletion*/
		if(root->left == NULL && root->right == NULL) {
			free(root);
			root = NULL;
		}
		/*Case 2: 1.No Left Child But Right Child*/
		else if(root->left == NULL) {
			temp = root;
			root = root->right;
			free(temp);
		}
		/*Case 2: 2.No Right Child But Left Child*/
		else if(root->right == NULL) {
			temp = root;
			root = root->left;
			free(temp);
		}
		/*Case 3: Node Has Both Right And Left Children*/
		else {
			temp->data = findmin(root->right);
			root->data = temp->data;
			root->right = deletethis(root->right, temp->data);
		}
	}
	return root;
}

int findmin(struct BST * root) {
	if(root->left == NULL) {
		return root->data;
	}
	return findmin(root->left);
}

void delet() {
	int junk;
	printf("\nEnter Element To Delete: ");
	scanf("%d", &junk);
	temp = deletethis(root, junk);
	printf("\n%d Deleted Successfully!",junk);
}

void main() {
	root = NULL;
	int choice;
	do {
		printf("\n------------BST------------\n");
		printf("\n1. Create \n2. Display \n3. Insert \n4. Delete \n5. Search \n9. Exit\n");
		printf("\n---------------------------\n");
		printf("\nEnter Choice: ");
		scanf("%d",&choice);
		switch(choice) {
			case 1 : create();break;
			case 2 : display();break;
			case 3 : insnew();break;
			case 5 : search();break;
			case 4 : delet();break;
			case 9 : printf("\nExiting...!\n");break;
			default: printf("\nEnter Valid Choice!\n");
		}
	}while(choice!=9);
	system("pause");
}
