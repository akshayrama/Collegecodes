
#include "stackimp.c"
#include "stackheader.h"
void main() {
	printf(" \n MENU: \t 1.Push an element \t 2. Pop an element \t 3.Display elements \t 4.Exit \n");
	struct node* top= NULL;
	while(1) {
		int ch;
		printf("\n Enter choice: ");
		scanf("%d",&ch);
		int val;
		struct node* ret;
		switch(ch) {
			case 1: 
				printf("\n Enter value to be inserted: ");
				scanf("%d",&val);
				top = push(top,val);
				break;
			case 2:
				ret = pop(top);
				printf("\n The deleted value is: %d",ret->data);
				top = top->next;
				free(ret);
				break;
			case 3:
				display(top);
				break;
			case 4:
				exit(1);
				break;
		}
	}
}
