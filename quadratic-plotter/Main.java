import java.awt.*;

import javax.swing.JFrame;

public class Main
{
	public static void main(String[] args) 
	{	
		JFrame frame = new JFrame ("Complex Calculator");
		frame.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
		Image icon = Toolkit.getDefaultToolkit().getImage("Quadratic.png");
		
		ComplexPanel window = new ComplexPanel();
		frame.getContentPane().add(window);
		frame.pack();
		frame.setLocation(200, 200);
		frame.setIconImage(icon);
		frame.setResizable(false);
		frame.setVisible(true);
		
	}
}
