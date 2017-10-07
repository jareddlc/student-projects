import java.text.DecimalFormat;
import java.text.NumberFormat;

public class Mycomplex 
{
	DecimalFormat dec = new DecimalFormat("#.##");	//Format for 2 decimal
	public double real, imag;						//Instance variables
	
	public Mycomplex(double a, double b) 
	{
		real=a;
		imag=b;
	}
	
	public String display(boolean imaginary)		//Displays the complex numbers
	{
		String str;	
		if (imaginary == true)
		{
			str = "( " +dec.format(real)+ " ± " + dec.format(imag)+ " i ) ";
		}
		else
		{
			str = "( " +dec.format(real)+ " ± " + dec.format(imag)+ " ) ";
		}
		return str;
	}

	public void add(Mycomplex a)
	{
		real = (real)+(a.real);
		imag = (imag)+(a.imag);
	}
	
	public void sub(Mycomplex a)
	{
		real = (real)-(a.real);
		imag = (imag)-(a.imag);
	}
	
	public void mul(Mycomplex a)
	{
		real = (real*a.real)-(imag*a.imag);
		imag = (real*a.imag)+(imag*a.real);
	}
	
	public void div(Mycomplex a)
	{
		real = ((real*a.real)+(imag*a.imag))/((Math.pow(a.real, 2))+(Math.pow(a.imag, 2)));
		imag = ((imag*a.real)-(real*a.imag))/((Math.pow(a.real, 2))+(Math.pow(a.imag, 2)));
	}
}
