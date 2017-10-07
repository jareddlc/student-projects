import java.awt.*;

public class PointHolder 
{
	public Point[] points;
	public int currentSize;
	public PointHolder(int size)
	{
		//final int LIMIT = 10;
		points = new Point[size];
	
	}
	
	public Point[] getPoints()
	{
		return points;
	}
	
	public void addPoint(Point p)
	{
		if(currentSize == points.length-1)
			resize();
		
		points[currentSize++] = p;
	}
	
	public int check()
	{
		int x = 0;
		for (int i = 0; i < points.length; ++i)
		{
			if (points[i] == null)
			{
				x = i;
				break;
			}
			
		}		
		return x;
	}
	private void resize(){
		//out of bounds already..
			//resize to +20 size
		Point[] temp = new Point[points.length + 20];
		
		for(int i = 0; i < points.length; i ++){
			temp[i] = points[i];			
		}
		
		points = temp;
		Runtime.getRuntime().gc();
	}
}
