//double linked list
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
	struct node* prev;
};
struct node* insert(struct node* head, int val) {
	struct node* newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	if(head==NULL) {
		newnode->next = NULL;
		newnode->prev = NULL;
		head= newnode;
	}
	else {
		struct node* ptr = head;
		while(ptr->next!=NULL) {
			ptr=ptr->next;
		}
		newnode->prev = ptr;
		ptr->next = newnode;
		newnode->next = NULL;
	}
	return head;
}
struct node* delete(struct node*head, int val) {
	struct node* ptr = head;
	while(ptr!=NULL) {
		if(ptr->data == val ) {
			if(ptr!=NULL) 
				ptr->prev->next = ptr->next;
			if(ptr->next!=NULL) 
				ptr->next->prev = ptr->prev;
			return head;
		}
		ptr=ptr->next;
	}
}
void display(struct node* head) {
	struct node* ptr= head;
	while(ptr!=NULL) {
		printf("%d \t ",ptr->data);
		ptr= ptr->next;
	}
}
void main() {
	printf(" \n MENU: \t 1.Insert an element \t 2. Delete an element \t 3.Display elements \t 4.Exit \n");
	struct node* head= NULL;
	while(1) {
		int ch;
		printf("\n Enter choice: ");
		scanf("%d",&ch);
		int val;
		switch(ch) {
			case 1: 
				printf("\n Enter value to be inserted: ");
				scanf("%d",&val);
				head = insert(head,val);
				break;
			case 2:
				printf("\n Enter the value to be deleted: ");
				scanf("%d",&val);
				head = delete(head,val);
				break;
			case 3:
				display(head);
				break;
			case 4:
				exit(1);
				break;
		}
	}
}

		
		
