
public class ListQueueTester {
	
	public static void main(String[] args)
	{
		ListQueue<Integer> myQueue = new ListQueue<Integer>();
		
		myQueue.enqueue(67);
		myQueue.enqueue(79);
		myQueue.printQueue();
		myQueue.enqueue(9);
		myQueue.printQueue();
		System.out.println("Dequeue'd " + myQueue.dequeue());
		myQueue.printQueue();
	}

}
