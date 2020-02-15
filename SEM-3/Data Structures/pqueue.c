//priority queue using MinHeap
#include<stdio.h>
#include<stdlib.h>
int heap[30];
int maxsize  = 30;
int n=0;
void insert(int val) {
	if(n==maxsize-1) {
		printf("\n Element cannot be inserted as heap is full ");
		return;
	}
	heap[++n] = val;
	int i,t;
	for(i=n/2; i > 0 ; i=i/2) {
		if(heap[i] > heap[2*i]) {
			t = heap[i];
			heap[i] = heap[2*i];
			heap[2*i] = t;
		}
		else if(heap[i] > heap[2*i+1] && (2*i+1) <= n ) {
			t = heap[i];
			heap[i]  = heap[2*i+1];
			heap[2*i +1] = t;
		}
	}
}
void display() {
	for(int i=1;i<=n;i++) {
		printf(" %d \t",heap[i]);
	}
}
int delete() {
	if(n==0) {
		printf("\n Element cannot be deleted: ");\
		return -1;
	}
	int ret = heap[1];
	heap[1] = heap[n];
	n--;
	int i,t;
	for(i = 1; 2*i<= n ; i=i*2) {
		if(heap[i] > heap[2*i] && heap[2*i] < heap[2*i+1]) {
			t = heap[i];
			heap[i] = heap[2*i];
			heap[2*i] = t;
		}
		else if(heap[i] > heap[2*i+1] ) {
			t = heap[i];
			heap[i]  = heap[2*i+1];
			heap[2*i +1] = t;
		}
	}
	return ret;
}

void main() {
	printf("\n MENU: \t 1.Insert an element \t 2.Delete an element \t 3.Display \t 4.Exit \n ");
	while(1) {
		int ch;
		int val;
		printf("\n Enter choice: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				printf("\n Enter an element to insert into the heap: ");
				scanf("%d",&val);
				insert(val);
				break;
			case 2:
				printf("\n The deleted value is: %d \n ",delete());
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
				break;
		}
	}
}
				
	
