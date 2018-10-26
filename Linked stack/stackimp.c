//stack adt using list
#include "stackheader.h"
struct node {
	int data;
	struct node* next;
};
struct node* push(struct node* top, int val) {
	struct node* newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	if(top==NULL) {
		top = newnode;
		newnode->next = NULL;
	}
	else {
		newnode->next = top;
		top= newnode;
	}
	return top;
}
struct node* pop(struct node* top) {
	if(top==NULL) {
		return NULL;
	}
	else {	
		return top;
	}
}
void display(struct node*top) {
	struct node* ptr = top;
	while(ptr!=NULL) {
		printf(" %d \t",ptr->data);
		ptr=ptr->next;
	}
}
struct node* enqueue(struct node* top, int val ) {
	struct node* newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	struct node* ptr = top;
	while(ptr->next!=NULL) {
		ptr=ptr->next;
	}
	ptr->next = newnode;
	newnode->next = NULL;
}
			
