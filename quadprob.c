//quadratic probing
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};
struct node* hashtable[10];
int hashfunction( int key ) {
	return key%10;
}
void insert( int key) {
	struct node* newnode;
	newnode = (struct node*) malloc(sizeof(struct node));
	newnode -> data = key;
	newnode -> next = NULL;
	int insertindex = hashfunction(key);
	if(hashtable[insertindex]==NULL) {
		hashtable[insertindex] = newnode;
	}
	else {
		int k = insertindex;
		int i=1;
		int q;
		while(i<10) {
			int q;
			q  = k+ (i*i);
			q = q % 10;
			if(hashtable[q]==NULL) {
				hashtable[q] = newnode;
				break;
			}
			i++;
		}
	}
}
void delete(int key) {
	int deleteindex = hashfunction(key);
	if(hashtable[deleteindex]->data == key ) {
		hashtable[deleteindex] = NULL;
	}
	else {
		int k = deleteindex;
		int i=1;
		int q;
		while(i<10) {
			q = k +(i*i);
			q = q%10;
			if(hashtable[q]!=NULL && hashtable[q]->data==key) {
				hashtable[q] = NULL;
				break;
			}
			i++;
		}
	}
}
void display() {
	printf("\n");
	for(int i=0;i<10;i++) {
		if(hashtable[i]!=NULL) {
			printf("%d \t", hashtable[i]->data);
		}
		else {
			printf("\t ");
		}
	}
}
void main() {
	printf("MENU: \t 1.Insert \t 2. Display \t 3.Delete \t 4.Exit \n");
	while(1) {
		int ch;
		int val;
		printf("\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				printf("Enter a number to insert: ");
				scanf("%d",&val);
				insert(val);
				break;
			case 2:
				display();
				break;
			case 3:
				printf("Enter a number to delete: ");
				scanf("%d",&val);
				delete(val);
				break;
			case 4:
				exit(1);
				break;
		}
	}
}
	
