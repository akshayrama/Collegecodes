//topological sort
#include<stdio.h>
int indeg[10];
int vis[10];
int vertices[10];
int a[10][10];
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
	for(i=0;i<n;i++) {
		indeg[i] = 0;
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
				vis[i]=1;	
				printf("%d \t",i);
			}
			for(int k=0;k<n;k++) {
				if(a[i][k]==1 ) {
					indeg[k]--;
				}
			}
		}
		count++;
	}
	
}
		
