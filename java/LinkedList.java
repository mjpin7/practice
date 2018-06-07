/**
 * Class for the linked list. Generically made
 * 
 * @author MPinheiro
 *
 * @param <T>			The type of the list
 */
public class LinkedList<T> {
	
	private Node<T> head;			// Variable for the head of the list
	
	/* Constructor */
	public LinkedList()
	{
		this.head = null;
	}
	
	/**
	 * Method to print the list
	 */
	public void printList()
	{
		Node<T> n = head;
		
		System.out.print("List: ");
		
		while(n != null)
		{
			System.out.print(n.value + " ");
			n = n.next;
		}
		System.out.println();
	}
	
	/**
	 * Method to find the size of the list
	 * 
	 * @return			The size of the list
	 */
	public int size()
	{
		Node<T> n = head;
		int count = 0;
		
		while(n != null)
		{
			count++;
			n = n.next;
		}
		
		return count;
	}
	
	/**
	 * Method to check if the list is empty
	 * 
	 * @return			True or false, empty or not
	 */
	public boolean empty()
	{
		if(size() == 0)
			return true;
		
		return false;
	}
	
	/**
	 * Method to find the value at a certain index
	 * 
	 * @param index			The index to look in
	 * @return				The value at that index
	 */
	public T value_at(int index)
	{
		Node<T> n = head;
		
		// If list is empty
		if(empty())
		{
			System.out.println("List is empty, no values to search for");
			return null;
		}
		
		// If the index is past the scope
		if(index > size())
		{
			System.out.println("Invalid index");
			return null;
		}
		
		// Else, traverse the list
		for(int i = 1; i < index; i++)
			n = n.next;
		
		T val = n.value;
		
		return val;
	}
	
	/**
	 * Method to place a value at the beginning of the list
	 * 
	 * @param value			The value to insert
	 */
	public void push_front(T value)
	{
		Node<T> n = new Node<T>(value);
		
		n.next = head;
		head = n;
		
		System.out.println(value + " pushed to front!");
	}
	
	/**
	 * Method to remove and return the first value in the list
	 * 
	 * @return			The removed value
	 */
	public T pop_front()
	{
		if(empty())
		{
			System.out.println("No values to pop!");
			return null;
		}
		
		T val = head.value;
		head = head.next;
		return val;
	}
	
	/**
	 * Method to push a value to the end of a list
	 * 
	 * @param value			The value to insert
	 */
	public void push_back(T value)
	{
		Node<T> n = new Node<T>(value);
		Node<T> temp = head;
		
		if(empty())
		{
			head = new Node<T>(value);
			System.out.println(value + " pushed to back!");
			return;
		}
		
		while(temp.next != null)
			temp = temp.next;
		
		temp.next = n;
		
		System.out.println(value + " pushed to back!");
	}
	
	/**
	 * Method to remove and return the last element in the list
	 * 
	 * @return			The last element
	 */
	public T pop_back()
	{
		Node<T> n = head;
		Node<T> prev = n;
		
		while(n.next != null)
		{
			prev = n;
			n = n.next;
		}
		
		T val = n.value;
		prev.next = n.next;
		
		return val;
	}
	
	/**
	 * Method to return front
	 * 
	 * @return			The first value
	 */
	public T front()
	{
		return head.value;
	}
	
	/**
	 * Method to return back
	 * 
	 * @return			The last value
	 */
	public T back()
	{
		Node<T> n = head;
		
		while(n.next != null)
			n = n.next;
		
		return n.value;
	}
	
	/**
	 * Method to insert a value at a given index
	 * 
	 * @param index			The index to insert to
	 * @param value			The value to insert
	 */
	public void insert(int index, T value)
	{
		if(index > size())
		{
			System.out.println("Index out of scope");
			return;
		}
		
		Node<T> n = new Node<T>(value);
		Node<T> temp = head;
		
		if(index == 0)
		{
			push_front(value);
			return;
		}
		
		for(int i = 1; i < index; i++)
			temp = temp.next;
		
		n.next = temp.next;
		temp.next = n;
	}
	
	public T erase(int index)
	{
		if(empty())
		{
			System.out.println("List empty, no values to erase");
			return null;
		}
		
		if(index > size())
		{
			System.out.println("Index out of scope");
			return null;
		}
		
		if(index == 0)
		{
			System.out.print("Value at index " + index + " erased!: ");
			return pop_front();
		}
		
		Node<T> n = head;
		
		for(int i = 1; i < index; i++)
			n = n.next;
		
		T val = n.next.value;
		n.next = n.next.next;
		
		System.out.print("Value at index " + index + " erased!: ");
		
		return val;
	}

}
