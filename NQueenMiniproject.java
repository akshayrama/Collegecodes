import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.text.NumberFormat;

public class NQueenMiniproject
{
	NQueenMiniproject()
	{
		JFrame jfrm = new JFrame("N Queen Problem");
		JPanel p = new JPanel();
		JPanel p1= new JPanel();
		p1.setLayout(new BoxLayout(p1,BoxLayout.Y_AXIS));
		p.setLayout(new BoxLayout(p,BoxLayout.Y_AXIS));
	        JFormattedTextField jf = new JFormattedTextField(NumberFormat.getNumberInstance());
		JLabel l1 = new JLabel("Enter the required chess board dimension: ");
		JButton jb = new JButton("Click to view output");
		jb. addActionListener ( new ActionListener()
		{
			public void actionPerformed (ActionEvent e)
			{ 
				int n = Integer.parseInt(jf.getText());
				placeQueens(n);
			}
		});		
		jfrm.setSize(300,200);
		p.add(l1);
		p.add(jf);
		p.add(jb);
		jfrm.add(p);
		jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jfrm.setVisible(true);
		
	}
	private static void placeQueens(int gridSize)
	{
   		/* N queen problem cannot be solved from postive integer ranging from 1 to 3. Therefore we must ensure that the number grid 			side is greater than or equal to 4. */  
  		if(gridSize<4)
		{
			System.out.println("No Solution available");
  		}
		else
		{
   			int[][] board = new int[gridSize][gridSize]; 
   			placeAllQueens(board, 0);
   			printBoard(board);
  		}
	}
	private static boolean placeAllQueens(int board[][], int row)
	{
		if(row>=board.length)
		{
   			return true;
  		}
 		boolean isAllQueensPlaced = false;
  		for (int j = 0; j < board.length; j++) 
		{
 			if(isSafe(board, row, j))
			{
    				board[row][j] = 1;
    				isAllQueensPlaced = placeAllQueens(board, row+1);
   			}
			if(isAllQueensPlaced)
			{
 				break;
   			}
			else
			{
    				board[row][j] = 0;
   			}
  		}
 	 	return isAllQueensPlaced;
	}
 	private static boolean isSafe(int board[][], int row, int col)
	{
 		//Checking Left Upper Diagonal
  		for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) 
		{
			if(board[i][j] == 1)
			{
    				return false;
   			}
  		}
 		//Checking Right Upper Diagonal
		for (int i = row-1, j = col+1; i >= 0 && j < board.length; i--, j++) 
		{
  			if(board[i][j] == 1)
			{
    				return false;
   			}
  		}
 		//Checking in same Column
		for (int i = row-1; i >= 0; i--) 
		{
			if(board[i][col] == 1)
			{
    				return false;
   			}
  		}
 		return true;
	}
	public static void printBoard(int[][] board)
	{
		
		String value = " ";
		for (int i = 0; i < board.length; i++) {
			for(int j=0 ;j< board.length; j++) {
				value+=board[i][j];
				value+= "  ";
			}
			value=value+"\n";
               	}
               	JFrame dfram= new JFrame("Output: ");
  		JTextArea g = new JTextArea();
  		dfram.setLayout(new GridLayout(board.length,board.length));
  		g.setText( value );
  		dfram.add(g);
  		dfram.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  		dfram.setVisible(true);
	} 
	public static void main(String[] args)
	{
		new NQueenMiniproject();
	}
}
