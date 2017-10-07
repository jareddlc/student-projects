import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class COUTPanel extends JPanel
{
	private JLabel inputLabel, resultLabel;
	public COUTPanel(String str)
	{
		inputLabel = new JLabel (str);
		resultLabel = new JLabel ("-----");
		
		//Panel settings
		setBackground (Color.lightGray);
		setPreferredSize (new Dimension(210, 30));
		
		//Adding to panel
		add(inputLabel);
		add(resultLabel);
	}
	public void setResult(String str)
	{
		resultLabel.setText(str);
	}
}
