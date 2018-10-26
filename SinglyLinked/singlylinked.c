//singly linked list
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
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
		newnode->next = NULL;
	}
	else {
		struct node* ptr = head;
		while(ptr->next!=NULL) {
			ptr=ptr->next;
		}
		ptr->next  =newnode;
		newnode ->next  =NULL;
	}
	return head;
}
struct node* delete(struct node* head, int val) {
	if(head->data == val) {
		struct node*del = head;
		head  = head ->next;
		free(del);
	}
	else {
		struct node* ptr = head;
		struct node* preptr = NULL;
		while(ptr!=NULL) {
			preptr= ptr;
			ptr=ptr->next;
			if(ptr->data == val) {	
				preptr->next= ptr->next;
				free(ptr);
				break;
			}
			ptr=ptr->next;
		}
	}
	return head;
}
void display(struct node*head) {
	struct node* ptr = head;
	while(ptr!=NULL) {
		printf(" %d \t",ptr->data);
		ptr=ptr->next;
	}
}
struct node* modify(struct node* head, int val) {
	struct node* ptr = head;
	while(ptr!=NULL) {
		if(ptr->data==val) {
			printf("\n Enter the modification data: ");
			scanf("%d",&ptr->data);
			break;
		}
		ptr=ptr->next;
	}
	return head;
}
void main() {
	printf(" \n MENU: \t 1.Insert an element \t 2. Delete an element \t 3.Display elements \t 4.Exit \t 5.Modfiy \n");
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
				printf("\n The element has been deleted. ");
				break;
			case 3:
				display(head);
				break;
			case 4:
				exit(1);
				break;
			case 5:
				printf("\n Enter data to be modfied: ");
				scanf("%d",&val);
				head = modify(head,val);
				break;
		}
	}
}
			
			
		
		
