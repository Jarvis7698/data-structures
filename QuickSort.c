/*
**	Quick Sort Implementation
*/

#include <stdio.h>
#include <stdlib.h>
 
void quicksort (int[], int, int);
 
int main() {
    int size,i;
    printf("\nEnter Size: ");
    scanf("%d",&size); 
    
    int list[size];
    printf("\nEnter %d Elements: ",size);
    for (i=0; i<size; i++) {
        scanf("%d",&list[i]);
    } 
    
    /*Before Sorting*/
    printf("\nBefore Sorting: ");
    for (i=0; i<size; i++) {
    	printf("%d ",list[i]);
	}
	printf("\n");
    
    /*Sorting Function Call*/
    quicksort(list, 0, size-1);
    
    /*After Sorting*/
    printf("\nAfter Sorting: ");
    for (i=0; i<size; i++) {
    	printf("%d ",list[i]);
	}
	printf("\n");
	
	system("pause");
	return 0;
}

void quicksort(int list[], int low, int high)
{
    int pivot,i,j,temp;
    
    if (low<high) {
        pivot = high;
        i = low;
        j = high;
        
        while (i<j) {
            while (list[i]<=list[pivot] && i<=high) {
            	i++;
			}
            while (list[j]>list[pivot] && j>=low) {
            	j--;
			}
            if (i<j) {
            	/*Simple Swap*/
            	temp = list[i];
                list[i] = list[j];
                list[j] = temp;
			}
        }
        /* Simple Swap*/
        temp = list[j];
        list[j] = list[pivot];
        list[pivot] = temp;
        
        /*Recursive Call*/
        quicksort(list, low, j-1);
        quicksort(list, j+1, high);
    }
}
