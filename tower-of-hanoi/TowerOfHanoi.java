import java.awt.Color;
import java.awt.Dimension;
import java.awt.Image;
import java.awt.Toolkit;

import javax.swing.JFrame;


public class TowerOfHanoi 
{
	public TowerOfHanoi()
	{
		//Getting using screen resolution
		Toolkit toolkit =  Toolkit.getDefaultToolkit();
		Dimension dim = toolkit.getScreenSize();

		//Creating new JFrame TowerGraph
		JFrame frame = new JFrame("Tower of Hanoi");
		frame.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
		
		//Creating Icon
		Image icon = Toolkit.getDefaultToolkit().createImage("icon.png");
		
		//Creating new window 
		TowerGraph window = new TowerGraph();
		frame.getContentPane().add(window);
		frame.pack();
		frame.setLocation((dim.width/2)-(window.width/2), (dim.height/2)-(window.height/2));
		//frame.setBackground(Color.lightGray);
		frame.setIconImage(icon);
		frame.setResizable(false);
		frame.setVisible(true);
		
		//Creating new JFrame TowerMenu
		JFrame menu = new JFrame("Tower of Hanoi");
		menu.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		TowerMenu windowmenu = new TowerMenu();
		menu.getContentPane().add(windowmenu);
		menu.pack();
		menu.setLocation(((dim.width/2)-(window.width/2))-(windowmenu.width+40), (dim.height/2)-(window.height/2));
		menu.setBackground(Color.lightGray);
		menu.setIconImage(icon);
		menu.setResizable(false);
		menu.setVisible(true);
		
	}
}
