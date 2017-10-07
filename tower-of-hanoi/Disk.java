
public class Disk 
{
	public int value;
	public Disk(int num)
	{
		value = num;
	}
	
	public String getStrValue()
	{
		String str = Integer.toString(value);
		return str;
	}
	
	public int getIntValue()
	{
		int intvalue = value;
		return intvalue;
	}
}
