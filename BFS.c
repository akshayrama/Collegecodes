#include<stdio.h>
int queue[20];
int adj[20][20];
int front =-1;
int rear=-1;
int vis[20];
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
void BFS(int source, int n) {
	vis[source]=1;
	enqueue(source);
	while(rear!=-1) {
		int k = dequeue();
		printf("%d \t",k);
		int j;
		for(j=0;j<n;j++) {
			if(adj[k][j]==1 && vis[j]==0) {
				enqueue(j);
				vis[j]=1;
			}
		}
	}
}
void main() {
	printf("\n Enter the number of vertices: ");
	int n;
	scanf("%d",&n);
	printf("\n Enter the adjacency matrix: ");
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			scanf("%d",&adj[i][j]);
		}
	}
	for(int i=0 ;i<n;i++) {
		vis[i]=0;
	}
	printf("\n Enter source vertex to start traversal :");
	int s;
	scanf("%d",&s);
	BFS(s,n);
}
	
	
	
