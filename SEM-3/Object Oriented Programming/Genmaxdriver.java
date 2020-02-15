import java.util.Scanner;
class Genmax <T extends Comparable<T>> {
	T maxnumber( T obj[],int n) {
		T max;
		max = obj[0];
		for(int i=0 ;i < n; i++ ) {
			if(obj[i].compareTo(max)> 0 ){
				max = obj[i];
			}
		}
		return max;
	}
}
class Genmaxdriver {
	public static void main(String[] args) {
		Integer a[] = new Integer[10];
		Scanner sc = new Scanner(System.in);
		int n;
		System.out.println("Enter the number of numbers: ");
		n = sc.nextInt();
		System.out.println("Enter the numbers: ");
		for(int i = 0;i<n;i++) {
			a[i] = sc.nextInt();
		}
		Genmax <Integer> g  = new Genmax <Integer> ();
		System.out.println("The maximum number is " + g.maxnumber(a,n) );
	}
}
		
