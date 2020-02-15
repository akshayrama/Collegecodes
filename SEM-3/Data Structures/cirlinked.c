//circularly linked list
#include<stdio.h> 
#include<stdlib.h>
#include<malloc.h>
struct node {
	int data;
	struct node* next;
};
struct node* insert(struct node* head, int val) {
	struct node* newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = val;
	if(head==NULL) {
		head = newnode;
		newnode->next= head;
	}
	else {
		struct node* ptr = head;
		while(ptr->next!=head) {
			ptr=ptr->next;
		}
		newnode->next = head;
		ptr->next = newnode;
	}
	return head;
}
struct node* delete(struct node* head, int val) {
	struct node* ptr = head;
	struct node* preptr;
	if(head->data==val) {
		while(ptr->next!=head) {
			ptr=ptr->next;
		}
		ptr->next = head->next;
		head = head->next;
		return head;
	}
	while(ptr->next!=head) {
		preptr = ptr;
		ptr=ptr->next;
		if(ptr->data==val) {
			preptr->next = ptr->next;
		}
	}
	return head;
}
void display(struct node* head) {
	struct node* ptr = head->next;
	printf("%d \t",head->data);
	while(ptr!=head) {
		printf("%d \t",ptr->data);
		ptr=ptr->next;
	}
}
void main() {
	printf("\n MENU : \t 1.Insert \t 2.Delete \t 3.Display \t 4.Exit \n ");
	struct node* head= NULL;
	while(1) {
		int f;
		printf("\n Enter choice: ");
		int ch;
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				printf("\n Enter a value to insert: ");
				scanf("%d",&f);
				head = insert(head,f);
				break;
			case 2:
				printf("\n Enter value to delete: ");
				scanf("%d",&f);
				head = delete(head,f);
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
		

