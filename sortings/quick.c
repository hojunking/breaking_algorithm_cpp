#include <stdio.h>
#define MAX 10
#define SWAP(x,y,t) (t=x, x=y, y=t)

/*
    O(n^2) time complexity
*/

int partition(int list[], int left, int right){
    int pivot = list[left];
    int tmp,j = left;
    
    for(int i = left+1; i <= right; i++)
        if(list[i] < pivot){
            j++;
            SWAP(list[i],list[j],tmp);
        }
    SWAP(list[left],list[j], tmp);
    return j;
}

void quick_sort(int list[], int left, int right) {
    if(left < right){
        int p = partition(list, left, right);
        quick_sort(list, left, p-1);
        quick_sort(list, p+1, right);
    }
}

void printList(int list[]) {
	printf("[ ");
	for (int i = 0; i < MAX; i++)
		printf("%2d ", list[i]);
	printf(" ]\n");
}

int main(void) {
	int list[MAX] = { 10,1,9,2,8,3,7,4,6,5 };
	printf("before : \n");
    printList(list);
	quick_sort(list, 0, MAX-1);
	
    printf("sorted : \n");
	printList(list);

}