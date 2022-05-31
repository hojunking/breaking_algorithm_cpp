#include <stdio.h>
#define MAX 10
#define HEAP_SIZE 20
#define SWAP(x,y,t) (t=x, x=y, y=t)
#define HEAP_FULL(n) (n == HEAP_SIZE-1)
#define HEAP_EMPTY(n) (!n)
/*
    O(nlog n) time complexity
*/
typedef struct element{
    int key;
} element;

element heap[HEAP_SIZE];
int n;


void push(int item){
    if(HEAP_FULL(n)) printf("heap is full!!\n");
    int i = ++n;
    printf("%d ", i);
    while((i != 1) && (item < heap[i /2].key)){
        heap[i] = heap[i/2];
        i /=2;
    }
    heap[i].key = item;
}

int pop(){
    if(HEAP_EMPTY(n)) printf("heap is empty!!\n");

    int parent =1, child =2;
    element tmp = heap[n--];
    element data = heap[parent];

    while(child <= n){
        if((child < n) && (heap[child].key) > (heap[child+1].key))
            child++;
        if(tmp.key < heap[child].key) break;
        heap[parent] = heap[child];
        parent = child;
        child *=2;
    }
    heap[parent] = tmp;
    return data.key;
}

void heap_sort(int list[]){
    int ln = MAX;
    for(int i=0; i<ln; i++)
        push(list[i]);
    
    for(int i=0; i<ln; i++)
        list[i] = pop();
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

	heap_sort(list);
	
    printf("\nsorted : \n");
	printList(list);
}