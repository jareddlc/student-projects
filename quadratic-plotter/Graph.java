import java.awt.*;
import javax.swing.*;

public class Graph extends JPanel
{
	public GraphPanel gPanel;
	public Graph() 
	{
		// Creating new Frame
		JFrame gframe = new JFrame ("Graph");
		gframe.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
		Image gicon = Toolkit.getDefaultToolkit().getImage("Quadratic.png");
		
		gPanel = new GraphPanel();
		gframe.getContentPane().add(gPanel);
		gframe.pack();
		gframe.setLocation(440, 200);
		gframe.setIconImage(gicon);
		gframe.setResizable(false);
		gframe.setVisible(true);
	}
}
