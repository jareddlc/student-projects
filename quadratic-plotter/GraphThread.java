
public class GraphThread implements Runnable{
	Thread thread;
	public static Graph graph;
	public GraphThread(){
		thread = new Thread(this,"Graph");
		thread.start();
	}
	public void run(){
		graph = new Graph();
	}
	public Graph getGraph(){
		return graph;
	}
}
