//topological sort
#include<stdio.h>
int queue[10];
int front=-1;
int rear=-1;
int indeg[10];
int vis[10];
	int vertices[10];
	int a[10][10];
void enqueue(int val) {
	if(rear==-1) {
		front=0;
		rear=0;
		queue[rear] = val;
	
	}
	else {
		rear++;
		queue[rear] = val;
	}
}
int dequeue() {
	if(rear==-1) {
		return -1;
	}
	else if(front==rear) {
		int d = queue[front];
		front=rear=-1;
		return d;
	}

	else {
		return queue[front++];
	}
}
void main() {
	
	printf("\n Enter the number of vertices: ");
	int n;
	scanf("%d",&n);
	int i,j;
	printf("\n Enter adjacency matrix : \n");
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			scanf("%d",&a[i][j]);
		}
	}	
	for(j=0;j<n;j++) {
		for(i=0;i<n;i++) {
			if(a[i][j] == 1) {
				indeg[j]++;
			}
		}
	}
	int count=0;
	while(count<n) {
		for(i=0;i<n;i++) {
			if(indeg[i]==0 && vis[i]!=1) {
				enqueue(i);
				vis[i]=1;
			}
		}
		while(rear!=-1) {
			int k = dequeue();
			printf("%d \t",k);
			for(i=0;i<n;i++) {
				if(a[k][i]==1 ) {
					indeg[i]--;
				}
			}
		}
		count++;
	}
}
	
	
