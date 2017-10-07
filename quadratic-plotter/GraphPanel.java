import java.awt.*;

import javax.swing.*;

public class GraphPanel extends JPanel
{
	public int gridunit = 5, x,y;
	public Point origin;
	
	public GraphPanel()
	{		
		//Panel settings
		setBackground (Color.lightGray);
		setPreferredSize (new Dimension(430, 430));
	}
	
	public void paint(Graphics g)
	{ 
		// Dynamically calculate size information
		Dimension size = getSize();
		// Setting Origin
		origin = new Point(size.width/2, size.height/2);
		//	Print debugging
		System.out.println("Size of window = " +size);
		System.out.println("Origin = " +origin);

		// Drawing Axis
		g.setColor(Color.black);
		g.drawLine(origin.x, -size.height,origin.x, size.height);
		g.drawLine(-size.width, origin.y, size.width, origin.y);
		
		// Axis Labels
		g.setColor(Color.red);
		g.drawString("y-axis", origin.x+10, 10);
		g.drawString("x-axis", 5, origin.y-10);
		
		// Grid Unit
		g.drawString("Grid Unit = " +gridunit+ "px", 0, 10);
		
		// Drawing grid lines
		// y-axis
		g.setColor(Color.darkGray);
		for (int i = gridunit; i<=size.height; i += gridunit)
			g.drawLine(origin.x-5, origin.y+i, origin.x+5, origin.y+i);
		
		for (int i = -gridunit; i>=-size.height; i += -gridunit)
			g.drawLine(origin.x-5,origin.y+i, origin.x+5, origin.y+i);
		// x-axis
		for (int i = gridunit; i<=size.width; i += gridunit)
			g.drawLine(origin.x+i, origin.y-5, origin.x+i, origin.y+5);
		
		for (int i = -gridunit; i>=-size.width; i += -gridunit)
			g.drawLine(origin.x+i, origin.y-5, origin.x+i, origin.y+5);
		
		// Draw oval
		g.setColor(Color.red);
		//g.fillOval(200, 200, 40, 40);
		//drawCircle(g,200,200);
		
	}
	
	public void setPoint(int a, int b)
	{
		x = a;
		y = b;
	}
	
	public Point getOrigin()
	{
		return origin;
	}
	
	public void drawCircle(Graphics g, int a, int b, Color c)
	{
		// Draw oval
		g.setColor(c);
		g.fillOval(a, b, 40, 40);	
	}
	
	public void drawLine(Graphics g, Point a, Point b,Color c)
	{
		g.setColor(c);
		g.drawLine(a.x, a.y, b.x, b.y);
	}
}