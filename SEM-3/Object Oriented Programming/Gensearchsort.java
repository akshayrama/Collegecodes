import java.util.Scanner;
interface searchsort <T> {
	public T[] sort(T obj[],int n);
	public boolean search(T obj[], T x);
}
class functionclass <T extends Comparable<T>>  implements searchsort <T> {
	public T[] sort( T obj[], int n) {
		int i=0;
		T temp;
		for(i=0;i < n; i++) {
			for( int j=i+1; j < n; j++) {
				if(obj[j].compareTo(obj[i]) < 0) {
					temp = obj[i];
					obj[i] = obj [j];
					obj[j] = temp;
				}
			}
		}
		return obj;
	} 
	public boolean search(T[] obj, T x) {
		int i=0;
		int flag=0;
		for(i=0; i < obj.length ; i++) {
			if(obj[i] == x) {
				System.out.println(" Element is found at position: " + i );
				flag=1;
				break;
			}
			else {
				flag = 0;
			}	
		}
		if(flag!=1) {
			return false;
		}
		else {
			return true;
		}
	}
}
class Gensearchsort {
	public static void main(String[] args) {
		Integer a[] = new Integer[10];
		Scanner sc = new Scanner(System.in);
		int n;
		System.out.println("Enter the number of numbers: ");
		n=sc.nextInt();
		int i;
		for(i=0;i<n;i++) {
			System.out.print("Enter: ");
			a[i] = sc.nextInt();
			System.out.println(" ");	
		}
		functionclass <Integer> ob = new functionclass <Integer> ();
		Integer sorted[] = ob.sort(a,n);
		System.out.println("The sorted list is:  ");
		for(int g =0; g < n ; g++ ) {
			System.out.print( sorted[g] + "\t" );
		}
		System.out.println(" ");
		int f;
		System.out.println("Enter an element to be searched: ");
		f=sc.nextInt();
		ob.search(a,f);
	}
}
		
		
		
	
					
					
				
				
	
