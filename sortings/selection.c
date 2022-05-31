#include <stdio.h>
#define MAX 10
#define SWAP(x,y,t) (t=x, x=y, y=t)

/*
    O(n^2) time complexity
*/

void selection_sort(int list[]) {
	int n = MAX, tmp;
	for (int i = 0; i < n-1; i++) {
		int least = i;
		for (int j = i + 1; j < n; j++)
			if (list[least] > list[j])
				least = j;
		if (least != i)
			SWAP(list[least], list[i], tmp);
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
	selection_sort(list);
	
    printf("\nsorted : \n");
	printList(list);

}