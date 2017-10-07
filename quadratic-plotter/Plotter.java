import java.awt.*;
import java.math.*;

public class Plotter 
{
	public double a, b, c, symmetry;
	public Point vertex;
	public Plotter(double x, double y, double z)
	{
		a = x;
		b = y;
		c = z;
	}
	public double getSymmetry()
	{
		symmetry = (-b/(2*a));
		System.out.println("line of symmetry = " +symmetry);
		return symmetry;
	}
	
	public Point setPoint(double a)
	{
		Point point = new Point();
		//Type casting and setting x value
		int i = (int)a;
		point.x = i;
		
		//Setting y value
		double temp = (Math.abs(a)*Math.pow(i, 2)+(b*i)+c);
		int j = (int)temp;
		point.y = j;
		
		//System.out.print("point = " +point+ "\t");
		
		return point;
	}
}
