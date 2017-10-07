import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class TowerMenu extends JPanel
{
	public int width=100,height=100, diskSize=10;
	public JTextField input;
	public JLabel text;
	public Button button;
	public DiskHolder diskHolder;
	public TowerMenu()
	{
		//Panel settings
		setBackground (Color.lightGray);
		setPreferredSize (new Dimension(width, height));
		
		//Creating texts
		text = new JLabel("Number of Disks: ");
		input = new JTextField(5);
		
		//Creating button
		String buttonText = new String("Send");
		button = new Button(buttonText);
		button.addActionListener(new buttonListener());
		
		//Creating image icon
		ImageIcon icon = new ImageIcon ("logo_small.png");
		JLabel label = new JLabel ("", icon, SwingConstants.CENTER);
	
		//Adding to panel
		add(label);
		add(text);
		add(input);
		add(button);
		
		//Creating DiskHoler
		diskHolder = new DiskHolder(diskSize);
	}
	
	private class buttonListener implements ActionListener
	{	
		public void actionPerformed (ActionEvent event)
		{	
			int inputInt = Integer.parseInt(input.getText());
			System.out.println("input is : " +inputInt);
			
			for(int i=0; i<inputInt; i++)
			{
				Disk disk =  new Disk(i);
				diskHolder.addDisk(disk);
			}
			System.out.println("Disk Holder contains: " +diskHolder.getDiskLength());
			
			for(int i=0; i<diskHolder.getDiskLength()-1;i++)
			{
				System.out.println(diskHolder.getSingleDisk(i).getStrValue());
				//System.out.println(diskHolder.getSingleDisk(0).getStrValue());
			}
		}
	}
}
