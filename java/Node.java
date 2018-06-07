/**
 * Class for the node. Generically made
 * 
 * @author MPinheiro
 *
 * @param <S>			The type of the node
 */
public class Node<S> {
	
	public Node<S> next;			// Pointer to the next node
	public S value;					// The value in the node
	
	/* Constructor */
	public Node(S value)
	{
		this.value = value;
		this.next = null;
	}

}
