#include <stdio.h>
#define MAX 10
#define SWAP(x,y,t) (t=x, x=y, y=t)
/*
    O(nlog n) time complexity
*/

void merge(int list[], int left, int mid, int right){
    int low = left, high = mid +1;
    int tmp, k =left;
    int t[MAX];

    while((low <= mid) && (high <= right)){
        if(list[low] > list[high])
            t[k++] = list[high++];
        else t[k++] = list[low++];
    }

    while(low <= mid){
        t[k++] = list[low++];
    }

    for(int i = left; i <k; i++)
        list[i] = t[i];
}

void merge_sort(int list[], int left, int right) {
    if(left < right){
        int mid = (left + right)/2;
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        merge(list, left, mid, right);
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

	merge_sort(list,0,MAX-1);
	
    printf("\nsorted : \n");
	printList(list);

}