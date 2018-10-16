import java.util.Scanner;
import java.util.LinkedList;
class Genlinked <T> {
	LinkedList <T> obj = new LinkedList <T> ();
	void add(T x ) {
		obj.add(x);
		System.out.println("Element has been added. ");
	}
	void delete(int position) {
		System.out.println("Element deleted is: " + obj.get(position) );
		obj.remove(position);
	}
	void display() {
		System.out.println(obj);
	}
	
}
class Genlinkeddriver {
	public static void main(String[] args) {
		Genlinked <String> g = new Genlinked <String> ();
		Scanner sc = new Scanner(System.in);
		System.out.println(" MENU: \t 1.Insert \t 2.Delete \t 3.Display \t 4.Exit \n");
		while(true) {
			int ch;
			System.out.println("Enter your choice: ");
			ch = sc.nextInt();
			switch(ch) {
				case 1:
					String h;
					System.out.println("Enter element: ");
					h = sc.next();
					g.add(h);
					break;
				case 2:
					int pos;
					System.out.println("Enter position to delete element: ");
					pos = sc.nextInt();
					g.delete(pos);
					break;
				case 3:
					g.display();
					break;
				case 4:
					System.exit(1);
					break;
			}
		}
	}
}
					
		
