#include <stdio.h>
#define MAX 10
#define SWAP(x,y,t) (t=x, x=y, y=t)

/*
    O(n^2) time complexity
*/

void insertion_sort(int list[]) {
	int n = MAX, tmp;
	for(int i =1; i<n; i++)
		for(int j=i; 0 < j; j--)
			if(list[j-1] > list[j])
				SWAP(list[j-1], list[j], tmp);
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
	insertion_sort(list);
	
    printf("sorted : \n");
	printList(list);

}