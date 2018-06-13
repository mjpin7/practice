/**
 * Class for the queue implemented with a linked list
 * 
 * @author MPinheiro
 *
 * @param <T>				The type of the Queue
 */
public class ListQueue<T> {
	
	/**
	 * Class for the node in the linked list
	 * 
	 * @author MPinheiro
	 *
	 * @param <S>			The type of the node
	 */
	private class Node<S>{
		private S key;				// The key
		private Node<S> next;		// Pointer to the next node in list
		
		/* CONSTRUCTOR */
		public Node(S key)
		{
			this.key = key;
			this.next = null;
		}
	}
	
	
	Node<T> first, last;			// Pointer to beginning and end of the queue
	
	/* CONSTRUCTOR */
	public ListQueue()
	{
		this.first = this.last = null;
	}
	
	/**
	 * Method to add a node to the end of the queue
	 * 
	 * @param value				The value to add
	 */
	public void enqueue(T value)
	{
		// Create new node
		Node<T> newNode = new Node<T>(value);
		
		// If the node is empty, set the first and last to the new node
		if(empty())
		{
			this.first = this.last = newNode;
			System.out.println("Enqueue'd " + value);
			return;
		}
		
		// Add the node to the list, and point the end to it
		this.last.next = newNode;
		this.last = newNode;
		System.out.println("Enqueue'd " + value);
		return;
		
	}
	
	/**
	 * Method to remove a node from the front of the list
	 * 
	 * @return
	 */
	public T dequeue()
	{
		// If empty
		if(empty())
			return null;
		
		// Store the beginning in temp, and set the front to the next value
		Node<T> temp = this.first;
		this.first = this.first.next;
		
		// If the front becomes null, set the end to null as well (empty)
		if(this.first == null)
			this.last = null;
		
		// Return the value
		return temp.key;
	}
	
	/**
	 * Method to check if the queue is empty
	 * 
	 * @return				True or false, Empty or not
	 */
	public boolean empty()
	{
		if(this.first == null)
			return true;
		
		return false;
	}
	
	public void printQueue()
	{
		Node<T> temp = this.first;
		System.out.print("The queue is: ");
		
		while(temp != null)
		{
			System.out.print(temp.key + " ");
			temp = temp.next;
		}
		System.out.println();
	}

}
