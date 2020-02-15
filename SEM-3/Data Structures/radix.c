//radix sorting
#include<stdio.h>
int maximum( int a[] , int n) {
	int max = a[0];
	for(int i=1; i<n;i++) {
		if(a[i] > max) 
			max  =a[i];
	}
	return max;
}
void radixsort( int a[], int n) {
	int largestval = maximum(a,n);
	int i=0;
	int divisor =1;
	int buckets[10][10];
	int buckets_per_val[10];
	int number_of_passes = 0;
	while(largestval >0) {
		largestval/=10;
		number_of_passes++;
	}
	for(i=0;i< number_of_passes; i++) {
		for(int j=0;j<10;j++) { //Initialising the number of numbers for a certain remainder to be 0 where remainder is between 0 and 10
			buckets_per_val[j] = 0;
		}
		for(int k=0;k<n;k++) {
			int remainder = (a[k] / divisor) % 10;
			buckets[remainder][buckets_per_val[remainder]] = a[k];
			buckets_per_val[remainder]+=1;
		}
		int i=0;
		for(int j = 0;j<10;j++) {
			for(int k=0;k< buckets_per_val[j] ; k++) {
				a[i] = buckets[j][k];
				i++;
			}	
		}
		divisor*=10;
	}
	printf("Elements after sorting: \n");
	for(i=0;i<n;i++) {
		printf("%d \n",a[i]);
	}
}
void main() {
	int a[10];
	int i;
	printf("\n Enter the number of numbers: ");
	int n;
	scanf("%d",&n);
	printf("\n Enter array: \n");
	for(i=0;i<n;i++) {
		printf("\n Enter: ");
		scanf("%d",&a[i]);
	}
	radixsort(a,n);
}
		
