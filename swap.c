//swapping two elements in a linked list
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};
struct node* head = NULL;
void display() {
	struct node* ptr = head;
	while( ptr!= NULL) {
		printf(" %d \t" , ptr -> data);
		ptr = ptr -> next;
	}
}
struct node* insert( int value ) {
	struct node* newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode -> data = value;
	newnode -> next = NULL;
	if( head == NULL) {
		head = newnode;
		return head;
	}
	struct node* ptr;
	ptr = head;
	while(ptr -> next != NULL ){
		ptr = ptr -> next;
	}
	ptr -> next = newnode;
	return head;
}
struct node* swap ( int v1, int v2 ){ 
	struct node* ptr1 = head;
	struct node* preptr1 = NULL;
	struct node* ptr2 = head;
	struct node* preptr2 = NULL;
	while( ptr1 -> next != NULL ) {
		if(ptr1 -> data == v1 ){
			break;
		}
		preptr1 = ptr1;
		ptr1 = ptr1 -> next;
		
	}
	while( ptr2 -> next != NULL ) {
		if(ptr2 -> data == v2 ){	
			break;
		}
		preptr2 = ptr2;
		ptr2 = ptr2 -> next;
	}
	if(preptr1 == NULL ) {
		head = ptr2;
	}
	else {
		preptr1 -> next = ptr2;
	}
	if(preptr2 == NULL ) {
		head = ptr1;
	}
	else {
		preptr2 -> next = ptr1;
	}
	struct node* temp = ptr1 -> next;
	ptr1 -> next = ptr2 -> next;
	ptr2 -> next = temp;
	return head;
}
void main() {
	while(1) {
	printf("\n MENU: \n 1. Insert an element \n 2. Swap two elements \n 3. Display the linked list \n 4. Exit \n");
	int ch;
	printf("\n Enter choice: ");
	scanf("%d",&ch);
	int value;
	int v1, v2;
	switch(ch) {
		case 1:
			printf("\n Enter the value to insert into the list: ");
			scanf("%d",&value);
			head = insert(value);
			break;
		case 2:
			printf("\n Enter two elements to swap: ");
			scanf("%d %d",&v1,&v2);
			head = swap(v1,v2);
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

			
