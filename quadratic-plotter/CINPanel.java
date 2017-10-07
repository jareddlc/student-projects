import java.awt.*;
import javax.swing.*;

public class CINPanel extends JPanel
{
	public JTextField a,b,c;			//Global vars
	public CINPanel()
	{
		JLabel x2 = new JLabel ("X²+");
		JLabel x = new JLabel ("X+");
		a = new JTextField(1);
		b = new JTextField(1);
		c = new JTextField(1);
		
		//Panel settings
		setPreferredSize (new Dimension(210, 30));
		setBackground (Color.lightGray);
		
		//Adding to panel
		add(a);
		add(x2);
		add(b);
		add(x);
		add(c);	
	}
}
