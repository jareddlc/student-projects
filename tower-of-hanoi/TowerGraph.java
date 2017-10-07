import java.awt.*;
import javax.swing.*;

public class TowerGraph extends JPanel
{
	public int width=430,height=430, grid=20;
	public Point origin;
	public TowerGraph()
	{
		//Panel settings
		setBackground (Color.lightGray);
		setPreferredSize (new Dimension(width, height));
	}
	
	public void paint(Graphics g)
	{
		//Logo
		
		//Dynamically calculate size information
		Dimension size = getSize();
		
		//Setting Origin
		origin = new Point(size.width/2, size.height/2);
		
		//Print debugging
		System.out.println("Size of window = " +size);
		System.out.println("Origin = " +origin);
						
		//Drawing grid lines
		g.setColor(Color.lightGray);
		for(int i=grid; i<=size.height; i+=grid)
			g.drawLine(size.width, 0+i, -size.width, 0+i);
		for(int i=grid; i<=size.width; i+=grid)
			g.drawLine(0+i, size.height, 0+i, -size.height);
		
		//Drawing Axis
		g.setColor(Color.darkGray);
		g.drawLine(origin.x, size.height, origin.x, -size.height);
		g.drawLine(size.width, origin.y, -size.width, origin.y);
		
		//Drawing square
		/*
		g.setColor(Color.red);
		g.fillRect(origin.x, origin.y, grid, grid);
		g.setColor(Color.black);
		g.drawString("1", origin.x+(grid/2), origin.y+(grid-5));
		*/
		Disk d1 = new Disk(1);
		Disk d2 = new Disk(2);
		Disk d3 = new Disk(3);
				
		Point col1row1 = new Point(origin.x+grid, origin.y+(grid*-3));
		Point col1row2 = new Point(origin.x+grid, origin.y+(grid*-2));
		Point col1row3 = new Point(origin.x+grid, origin.y+(grid*-1));
		
		drawDisk(g,d1,col1row1,Color.blue);
		drawDisk(g,d2,col1row2,Color.green);
		drawDisk(g,d3,col1row3,Color.red);
		
	}
	
	public void drawDisk(Graphics g, Disk d, Point p, Color c)
	{
		g.setColor(c);
		g.fillRect(p.x, p.y, grid, grid);
		g.setColor(Color.black);
		g.drawString(d.getStrValue(),p.x+(grid/2),p.y+(grid));
		
	}
}
