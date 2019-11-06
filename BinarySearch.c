/* BINARY SEARCHING */

#include<stdio.h>
#include<stdlib.h>

int main() {
	int mid, first, last, i, size, target, flag = 0;
	printf("\nEnter Number Of Elements: ");
	scanf("%d",&size);
	
	int a[size];
	printf("\nEnter %d Elements: ",size);
	for(i=0;i<size;i++) {
		scanf("%d",&a[i]);
	}
	
	printf("\nYou Entered: ");
	for(i=0;i<size;i++) {
		printf("%d ",a[i]);
	}
	
	printf("\n\nEnter Target: ");
	scanf("%d",&target);
	
	/* BINARY SEARCHING ALGORITHM */
	first = 0;
	last = size-1;
	while(first <= last) {
		mid = (first + last)/2;
		if(target < a[mid]) {
			last = mid-1;
		}
		else if(target == a[mid]) {
			printf("\nElement Found At Position %d!\n",mid+1);
			flag = 1;break;
		}
		else if(target > a[mid]) {
			first = mid+1;
		}
	}
	if(flag==0) {
		printf("\nElement Not Found!\n");
	}
	
	system("pause");
	return 0;
}
