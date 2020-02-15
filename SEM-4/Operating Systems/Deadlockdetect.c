
#include<stdio.h>
#include<string.h>
void DeadlockDetect (int pno, int rno , int alloc [][10] , int max [][10] , int resource[10]) {
	// Calculating the need matrix  
	int i,j;
	int need[10][10];
	for(i=0 ; i< pno ; i++) {
		for(j =0 ; j< rno; j++) {
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	//printing need matrix
	printf("\n Printing need matrix: \n");
	for ( i= 0 ; i < pno ; i++ ){
		for( j = 0; j < rno ; j++) {
			printf("%d ",need[i][j]);
		}
		printf("\n");
	}
	int available [10];
	for( i= 0; i < rno ; i++) {
		available[i] = resource[i] ;
	}
	int finish[10];
	for( i =0; i < pno ; i++) {
		finish[i] = 0;
	}
	i = 0;
	int num = 0;
	printf("\n Printing the sequence of execution: \n");
	int safe = 0;
	// printing available vector
	printf(" \n Available vector: ");
	for( j = 0; j < rno ; j++) {
		printf("%d ",available[j]);
	}	
	i = 0;
	int sample = 0; 
	while( num < pno) {
		if(sample > 10 ) {
			break;
		}
		int ct = 0;
		for( j = 0;j < rno ;j++ ) {
			if ( need[i][j] <= available[j] && finish[i] == 0) {
				ct++;
			}
		}
		if( ct == rno ) {
			num++;
			finish[i] = 1;
			printf("\n P%d is executed. ", i); 
			safe = 1;
			for(int j = 0 ;j < rno ; j++) {
				available[j] += alloc[i][j];
			}
			printf(" \n Available vector: ");
			for( j = 0; j < rno ; j++) {
				printf("%d ",available[j]);
			}
		}
		i++;
		if ( i > pno - 1) {
			i = 0;
		}
		sample++;
	}
	int flag = 1;
	for( i = 0;i < pno ; i++ ){
		if(finish[i]!=1) {
			printf(" \n P%d produces deadlock.\n " , i );
			flag = 0;
		}	
	}
	if(flag != 0){
		printf("\n Processes have executed without deadlock. ");
	}
		 
}
void main() {
	int pno;
	int rno;
	int alloc [10][10];
	int max[10][10];
	int resource[10];
	printf(" Enter the number of process: ");
	scanf("%d", &pno);
	printf("\n Enter the number of resource: ");
	scanf("%d",&rno);
	int i,j;
	//Entering resource instances
	printf("\n Enter resource instances for each resource: ");
	for(i=0; i < rno; i++){
		printf("\n Enter R%d : ",i);
		scanf("%d" , &resource[i]);
	}
	// Entering allocation matrix 
	printf("\n Enter the allocation matrix: ");
	for(i=0 ; i< pno ; i++) {
		printf("\n Enter for P%d: ", i);
		for(j =0 ; j< rno; j++) {
			scanf("%d", &alloc[i][j]) ;
		}
	}
	// Entering max matrix 
	printf("\n Enter the max matrix: ");
	for(i=0 ; i< pno ; i++) {
		printf("\n Enter for P%d: ", i);
		for(j =0 ; j< rno; j++) {
			scanf("%d", &max[i][j]) ;
		}
	}
	DeadlockDetect (pno,rno, alloc , max, resource);
}
