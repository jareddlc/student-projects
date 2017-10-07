public class Quadratic 
{
	public double a, b, c, root1, root2;					//Global variables
	public boolean imaginary;								//check for complex
	public Quadratic(double x, double y, double z) 
	{
		//setting instance variables to function call
		a = x; 
		b = y;
		c = z;
		
		a = 2*x;									//2a
		b = -y;										//-b
		//c 										//Square root(b^2-4ac)
		double d = (Math.pow(y, 2))-(4*(x*z));		//(b^2-4ac) used to check for negative
		
		check_imaginary(d);							//checks for negative value											
		
		if (imaginary == true)
		{
			c = Math.sqrt((-1)*(Math.pow(y, 2)-(4*(x*z))));
			//set complex
			root1 = b/a;
			root2 = c/a;
		}
		else
		{
			c = Math.sqrt(Math.pow(y, 2)-(4*(x*z)));
			root1 = b/a;
			root2 = c/a;
		}
	}
	
	public void check_imaginary(double q)
	{
		if (q < 0)
			imaginary = true;
		else
			imaginary = false;
	}
	
	public boolean get_bool()
	{
		return imaginary;
	}
	
	public double getRoot1()
	{
		return root1;
	}
	
	public double getRoot2()
	{
		return root2;
	}
	
	
	public void print()
	{
		//prints out each individual instance variable
		//checks boolean and appends i if true
		if (imaginary == false)
		{
			System.out.println("a = " +a+ "\nb = " +b+ "\nc = " +c+ "\nroot1 = " +root1+ "\nroot2 = " +root2+"");
		}
		else
		{
			System.out.println("a = " +a+ "\nb = " +b+ "\nc = " +c+ "\nroot1 = " +root1+ "\nroot2 = " +root2+"i");
		}		
	}
}
