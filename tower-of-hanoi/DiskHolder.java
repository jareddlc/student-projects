
public class DiskHolder 
{
	public Disk[] disks;
	public int currentSize=0, addSize = 10;
	public DiskHolder(int size)
	{
		disks = new Disk[size];
	}
	
	public Disk[] getDisk()
	{
		return disks;
	}
	
	public Disk getSingleDisk(int i)
	{
		return disks[i];
	}
	
	public int getDiskLength()
	{
		return disks.length;
	}
	
	public void addDisk(Disk d)
	{
		if(currentSize == disks.length-1)
		{
			resize();
		}
		disks[currentSize++] = d;
	}
	
	public void resize()
	{
		Disk[] temp = new Disk[disks.length+addSize];
		
		for(int i=0; i<disks.length; i++)
		{
			temp[i] = disks[i];
		}
		
		disks = temp;
		Runtime.getRuntime().gc();
	}
}
