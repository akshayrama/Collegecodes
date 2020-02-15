//circular queue
#include<stdio.h>
#include<stdlib.h>
int queue[30];
int size = 6;
int front =-1;
int rear =-1;
void enqueue(int val) {
	if(rear==size-1 && front==0) {
		printf("\n Item cannot be inserted :");
		return;
	}
	if(rear==-1 && front == -1) {
		front = rear = 0;
	}
	else if( rear== size-1 && front!=0) {
		rear = 0;
	}
	else {
		rear++;
	}
	queue[rear] = val;
}
int isempty() {
	if ( front==-1 && rear == -1) {
		return 1;
	}
	else {
		return 0;
	}
}
int dequeue() {
	if(rear==-1) {
		printf("\n Item cannot be deleted. ");
		return -1;
	}
	int retval = queue[front];
	if(front == rear) {
		front = rear = -1;
	}
	else if( front == size-1) {
		front = 0;
	}
	else {
		front++;
	}
	return retval;
}
void display() {
	if(front <= rear) {
		for(int i=front; i<=rear; i++) {
			printf("%d \t",queue[i]);
		}
	}
	else {
		for(int i = front; i <= size-1 ; i++) {
			printf("%d \t",queue[i]);
		}
		if(front > rear) {
			for(int i=0; i<= rear; i++) {
				printf("%d \t",queue[i]);
			}
		}	
	}
}
void main() {
	printf("\n MENU: \t 1.Enqueue \t 2. Dequeue \t 3. Display \t 4.Exit \n ");
	while(1) {
		printf("\n Enter choice: ");
		int ch;
		scanf("%d",&ch);
		int val;
		switch(ch) {
			case 1:
				printf("\n Enter value to insert: ");
				scanf("%d",&val);
				enqueue(val);
				break;
			case 2:
				printf("\n The deleted value is: %d \n",dequeue());
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
