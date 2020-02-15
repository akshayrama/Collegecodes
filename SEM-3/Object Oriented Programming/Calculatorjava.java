//swing calculator
import java.util.Scanner;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.lang.Math;
class Calculatorjava {
	JFrame jfrm;
	Calculatorjava() {
		jfrm = new JFrame("Calculator");
		jfrm.setSize(600,800);
		jfrm.setLayout(new GridLayout(3,3));
		JLabel jb = new JLabel();
		jfrm.add(jb);
		jb.setText("Enter two numbers: ");
		JTextField j1 = new JTextField("");
		JTextField j2 = new JTextField("");
		jfrm.add(j1);
		jfrm.add(j2);
		JButton jd = new JButton("+");
		JButton je = new JButton("-");
		JButton jf = new JButton("*");
		JButton jg = new JButton("/");
		JButton jh = new JButton("^");
		jfrm.add(jd);
		jfrm.add(je);
		jfrm.add(jf);
		jfrm.add(jg);
		jfrm.add(jh);
		JLabel ans = new JLabel();
		jd.addActionListener( new ActionListener() {
			public void actionPerformed( ActionEvent e) {
				int n1 = Integer.parseInt(j1.getText());
				int n2 = Integer.parseInt(j2.getText());
				int h = n1+ n2;
				String hd ="";
				hd+= h;
				ans.setText("The answer is:  " + hd);
			}	
		});
		je.addActionListener( new ActionListener() {
			public void actionPerformed( ActionEvent e) {
				int n1 = Integer.parseInt(j1.getText());
				int n2 = Integer.parseInt(j2.getText());
				int h = n1- n2;
				String hd ="";
				hd+= h;
				ans.setText("The answer is:  " + hd);
			}	
		});
		jf.addActionListener( new ActionListener() {
			public void actionPerformed( ActionEvent e) {
				int n1 = Integer.parseInt(j1.getText());
				int n2 = Integer.parseInt(j2.getText());
				int h = n1* n2;
				String hd ="";
				hd+= h;
				ans.setText("The answer is:  " + hd);
			}	
		});
		jg.addActionListener( new ActionListener() {
			public void actionPerformed( ActionEvent e) {
				int n1 = Integer.parseInt(j1.getText());
				int n2 = Integer.parseInt(j2.getText());
				int h = n1 / n2;
				String hd ="";
				hd+= h;
				ans.setText("The answer is:  " + hd);
			}	
		});
		jh.addActionListener( new ActionListener() {
			public void actionPerformed( ActionEvent e) {
				int n1 = Integer.parseInt(j1.getText());
				int n2 = Integer.parseInt(j2.getText());
				double h = Math.pow(n1,n2);
				String hd ="";
				hd+= h;
				ans.setText("The answer is:  " + hd);
			}	
		});
		jfrm.add(ans);
		jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jfrm.setVisible(true);
	}
	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				new Calculatorjava();
			}
		});
	}
}
		
