//double ended queue using arrays
#include<stdio.h>
#include<stdlib.h>
int capacity = 5;
int size = 0;
int deque[5];
int front = -1;
int rear = -1;
int isempty() {
	if(size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int isfull() {
	if(size == capacity) {
		return 1;
	}
	else {
		return 0;
	}
}
void enqueuelast(int val) {
	if(isfull()) {
		printf("\n Element cannot be inserted. ");
		
	}
	else {
		if(front==-1) {
			front = rear =0;
		}
		else if(rear==capacity-1) {	
			rear = 0;
		}
		else {
			rear++;
		}
		deque[rear] = val;
		size++;
	}
}
void enqueuefirst(int val) {
	if(isfull()) {
		printf("\n Element cannot be inserted. ");
	}
	else {
		if(front==-1) {
			front = rear= 0;
		}
		else if(front==0) {
			front= capacity - 1;
			
		}
		else {
			front--;
		}
		deque[front] = val;
		size++;
	}
}
int dequeuelast() {
	if(isempty()) {
		printf("\n Element cannot be deleted. ");
		return -1;
	}
	else {
		int retval = deque[rear];
		if(front == rear) {
			front = rear = -1;
		}
		else if( rear== 0 ){
			rear = capacity -1;
		}
		else {
			rear--;
		}
		size--;
		return retval;
	}	
}
int dequeuefirst() {
	if(isempty()) {
		printf("\n Element cannot be deleted: ");
		return -1;
	}
	else {
		int retval = deque[front];
		if(front==rear) {
			front = rear= -1;
		}
		else if(front==size -1) {
			front = 0;
		}
		else {
			front++;
		}
		size--;
		return retval;
	}
}
void display() {
	if(front<=rear) {
		for(int i=front ; i<=rear; i++) {
			printf("%d \t",deque[i]);
		}
	}
	else {
		for(int i=front;i<=capacity -1 ; i++ ) {
			printf("%d \t",deque[i]);
		}
		for(int i=0;i<=rear;i++) {
			printf("%d \t",deque[i]);
		}
	}
}
void main() {
	printf("\n MENU: \t 1.Enqueue at front \t 2.Enqueue at last  \t 3. Dequeue at front \t 4. Dequeue at last \t 5. Display \t 6.Exit \n ");
	while(1) {
		printf("\n Enter choice: ");
		int ch;
		scanf("%d",&ch);
		int val;
		switch(ch) {
			case 1:
				printf("\n Enter value to insert: ");
				scanf("%d",&val);
				enqueuefirst(val);
				break;
			case 2:
				printf("\n Enter value to insert: ");
				scanf("%d",&val);
				enqueuelast(val);
				break;
			case 3:
				printf("\n The deleted value is: %d \n",dequeuefirst());
				break;
			case 4:
				printf("\n The deleted value is: %d \n",dequeuelast());
				break;
			case 5:
				display();
				break;
			case 6:
				exit(1);
				break;
		}
	}
}

	
