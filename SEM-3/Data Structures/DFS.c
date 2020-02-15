#include<stdio.h>
#include<stdlib.h>
int stack[20];
int adj[20][20];
int vis[20];
int top=-1;
void push(int val) {
	top++;
	stack[top] =val;
}
int pop() {
	if(top==-1) {
		return -1;
	}
	else {
		return stack[top--];
	}
}
void DFS(int source,int n) {
	printf("%d \t",source);
	vis[source] = 1;
	push(source);
	int k = pop();
	if(k!=-1) {
		int j;
		for(j=0;j<n;j++) {
			if(adj[k][j] ==1  && vis[j]!=1) {
				DFS(j,n);
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
	DFS(s,n);
}
	
	
