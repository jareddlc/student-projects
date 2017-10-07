import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class ComplexPanel extends JPanel
{
	private Button press;
	CINPanel cIN1,cIN2;
	COUTPanel cOUT1,cOUT2,add,sub,mul,div;
	Quadratic quad1,quad2;
	Mycomplex complex1,complex2;
	Graph graph;
	PointHolder hold1, hold2;
	Point origin, previousPoint;
	int arraysize1 = 20, arraysize2 = 20;
	
	public ComplexPanel()
	{
		//Creating Labels
		JLabel form1 = new JLabel ("Enter the first quadratic:");
		JLabel form2 = new JLabel ("Enter the second quadratic:");
		//JLabel form = new JLabel ("aX�+bX+c");
		
		//Creating Input class
		cIN1 = new CINPanel();
		cIN2 = new CINPanel();
		
		//Creating Output class
		add = new COUTPanel("Addition:");
		sub = new COUTPanel("Subtraction: ");
		mul = new COUTPanel("Multiplication: ");
		div = new COUTPanel("Division: ");
		cOUT1 = new COUTPanel("Complex 1: ");
		cOUT2 = new COUTPanel("Complex 2: ");
		
		//Panel settings
		setBackground (Color.lightGray);
		setPreferredSize (new Dimension(210, 350));
		
		//Button settings
		String but = new String("Calculate!");
		press = new Button(but);
		press.addActionListener(new buttonListener());
		press.setForeground(Color.red);
		
		//Adding objects to panel
		add(form1);
		add(cIN1);
		add(form2);
		add(cIN2);
		add(press);
		add(cOUT1);
		add(cOUT2);
		add(add);
		add(sub);
		add(mul);
		add(div);
		
		//Creating new Graph
		graph = new Graph();
		hold1 = new PointHolder(arraysize1);
		hold2 = new PointHolder(arraysize2);
	}	

	private class buttonListener implements ActionListener
	{	
		public void actionPerformed (ActionEvent event)
		{			
			System.out.println("Button Click");
			origin = new Point(graph.gPanel.getOrigin());
			//Grabbing input
			double a = Double.parseDouble(cIN1.a.getText());
			double b = Double.parseDouble(cIN1.b.getText());
			double c = Double.parseDouble(cIN1.c.getText());
			double d = Double.parseDouble(cIN2.a.getText());
			double e = Double.parseDouble(cIN2.b.getText());
			double f = Double.parseDouble(cIN2.c.getText());
			
			//Creating new quadratics
			quad1 = new Quadratic(a,b,c);
			quad2 = new Quadratic(d,e,f);
			//Debug printing
			//quad1.print();
			//quad2.print();
			
			boolean bool1 = quad1.get_bool();
			boolean bool2 = quad2.get_bool();
			
			//Establish new complex
			complex1 = new Mycomplex(quad1.getRoot1(),quad1.getRoot2());
			complex2 = new Mycomplex(quad2.getRoot1(),quad2.getRoot2());

			
			//Doing Math
			cOUT1.setResult(complex1.display(bool1));
			cOUT2.setResult(complex2.display(bool2));	
			//Resetting complex class
			complex1 = new Mycomplex(quad1.getRoot1(),quad1.getRoot2());
			complex2 = new Mycomplex(quad2.getRoot1(),quad2.getRoot2());
			//Addition
			complex1.add(complex2);
			add.setResult(complex1.display(bool1));
			//Resetting complex class
			complex1 = new Mycomplex(quad1.getRoot1(),quad1.getRoot2());
			complex2 = new Mycomplex(quad2.getRoot1(),quad2.getRoot2());
			//Subtraction
			complex1.sub(complex2);
			sub.setResult(complex1.display(bool1));
			//Resetting complex class
			complex1 = new Mycomplex(quad1.getRoot1(),quad1.getRoot2());
			complex2 = new Mycomplex(quad2.getRoot1(),quad2.getRoot2());
			//Multiplication
			complex1.mul(complex2);
			mul.setResult(complex1.display(bool1));
			//Resetting complex class
			complex1 = new Mycomplex(quad1.getRoot1(),quad1.getRoot2());
			complex2 = new Mycomplex(quad2.getRoot1(),quad2.getRoot2());
			//Division
			complex1.div(complex2);
			div.setResult(complex1.display(bool1));	
			
			//Creating Plotters to get points
			Plotter function1 = new Plotter(a,b,c);
			Plotter function2 = new Plotter(d,e,f);
			
			//Lines of symmetry
			function1.getSymmetry();
			function2.getSymmetry();
			
			//Get 5 points for function1 RIGHT
			double x = -(arraysize1/2);
			System.out.println("Start point = " +x);
			for(int i = 0; i<arraysize1; i++)
			{
				hold1.addPoint(function1.setPoint(x));
				++x;
			}
			
			for (Point list : hold1.getPoints())
			{
				System.out.print(list +"\t");
			}
			

			for (int i=0; i<arraysize1;i++)
			{
				//Checks for previous point
				if (previousPoint == null)
					previousPoint = hold1.points[i];
				
				hold1.points[i].x = ((hold1.points[i].x)*graph.gPanel.gridunit)+(origin.x);
				hold1.points[i].y = ((hold1.points[i].y)*-graph.gPanel.gridunit)+(origin.y);
				graph.gPanel.drawLine(graph.gPanel.getGraphics(), previousPoint, hold1.points[i], Color.blue);
				previousPoint = hold1.points[i];
			}
			
			
			//Grabbing Graphics and repaint
			//graph.gPanel.drawCircle(graph.gPanel.getGraphics(), 200,200,Color.red);
			graph.repaint();
			
		}
	}
}
