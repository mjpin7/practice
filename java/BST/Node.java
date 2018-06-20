/**
 * Class for the nodes of the binary search tree
 * 
 * @author MPinheiro
 *
 */
public class Node {
	int data;
	Node left, right;
	
	/* CONSTRUCTOR */
	public Node(int num)
	{
		this.data = num;
		this.left = this.right = null;
	}

}
