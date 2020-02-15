//hashing
#include<stdio.h>
#include<stdlib.h>
struct node {
	int key;
	struct node* next;
};
int hashfunction( int key, int n)
{
	return ( key%n);
}
int n=10;
struct node* hashtable[10];
void insert(int key) {
	int toinsert = hashfunction(key,n);
	for(int i=0; i<n ; i++) {
		if(i == toinsert ) {
			struct node* newnode;
			newnode = (struct node*)malloc(sizeof(struct node));
			newnode->key = key;
			if(hashtable[i]==NULL) {
				newnode->next = NULL;
				hashtable[i] = newnode;
			}
			else {
				newnode->next = hashtable[i];
				hashtable[i] = newnode;
			}
		}
	}
	
}
void delete(int val) {
	int delpos = hashfunction(val,n);
	for(int i=0;i<n;i++) {
		if(delpos==i) {
			struct node* temp = hashtable[i];
			struct node* preptr;
			if(hashtable[i]->key==val) {
				hashtable[i] = hashtable[i] ->next;
			}
			else {
				while(temp!=NULL) {
					preptr = temp;
					temp = temp->next; 
					if(temp->key == val) {
						preptr->next = temp->next;
						break;
					}
				}	
			}
		}
	}
	
}						
void display() {
	for(int i=0; i<n; i++ ) {
		struct node* temp = hashtable[i];
		while(temp!= NULL) {
			printf("%d ",temp->key);
			temp=temp->next;
		}
		printf("\n");
		
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
		
		
	

						
			
	

