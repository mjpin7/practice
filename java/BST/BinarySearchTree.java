/**
 * Class for the binary search tree
 * 
 * @author MPinheiro
 *
 */
public class BinarySearchTree {
	
	private Node root;
	
	/* CONSTRUCTOR */
	public BinarySearchTree()
	{
		this.root = null;
	}
	
	/**
	 * Method to call the insert1 method
	 * 
	 * @param value				The value to insert
	 */
	public void insert(int value)
	{
		this.root = insert1(this.root, value);
	}
	
	/**
	 * Method to insert a value into the binary search tree
	 * 
	 * @param root				The root node, or the node being passed in recursively
	 * @param value				The value to insert
	 * @return					The new 
	 */
	private Node insert1(Node root, int value)
	{
		// If its empty or at the end of the branch, set root equal to a new node
		if(root == null)
		{
			root = new Node(value);
			return root;
		}
		
		// Else, traverse down the tree in the correct direction
		// If value is less than the data at the node, traverse to the left
		if(value < root.data)
			root.left = insert1(root.left, value);
		// If value is greater than the data at the node, traverse to the right
		else if(value > root.data)
			root.right = insert1(root.right, value);
		
		return root;
	}
	
	/**
	 * Method to call the recursively implemented inorder method
	 */
	public void inOrder()
	{
		inOrder1(root);
	}
	
	/**
	 * Method to recursively traverse the tree in order
	 * 
	 * @param root
	 */
	private void inOrder1(Node root)
	{
		if(root == null)
			return;
		
		inOrder1(root.left);
		System.out.print(root.data + " ");
		inOrder1(root.right);
	}
	
	/**
	 * Method to call the recursive delete method
	 * 
	 * @param value			The value to delete
	 */
	public void delete(int value)
	{
		if(isInTree(value))
		{
			root = delete1(root, value);
			System.out.println("Value " + value + " deleted from tree");
		}
		else
			System.out.println("Value " + value + " not in tree");
		
	}
	
	/**
	 * Method to recursively delete a given value in the tree
	 * 
	 * @param root			The root node
	 * @param value			The value to delete
	 * @return				The new root of the tree
	 */
	private Node delete1(Node root, int value)
	{
		// If tree is empty or at the end of the tree
		if(root == null)
			return root;
		
		if(value < root.data)
			root.left = delete1(root.left, value);
		else if(value > root.data)
			root.right = delete1(root.right, value);
		// If found the value to be deleted
		else
		{
			// Case 1 & 2: One child or no children (leaf)
			if(root.left == null)
				return root.right;
			else if(root.right == null)
				return root.left;
			
			// Case 3: Has two children, must find successor
			
			// This is the next minimum value in the tree
			root.data = minValue(root.right);
			
			// Delete the end node that we found the minimum value from
			root.right = delete1(root.right, root.data);
		}
		
		return root;
	}
	
	/**
	 * Method to find the minimum value from a given node
	 * 
	 * @param root
	 * @return
	 */
	private int minValue(Node root)
	{
		// Store the minimum
		int min = root.data;
		
		// Traverse down the tree to the left (to find the smallest number)
		while(root.left != null)
		{
			min = root.left.data;
			root = root.left;
		}
		
		return min;
	}
	
	/**
	 * Method to call the recursive isInTree method
	 * 
	 * @param value				The value to check for
	 * @return					True or false, in tree or not
	 */
	public boolean isInTree(int value)
	{
		Node verdict = isInTree1(root, value);
		
		// If the node returned is a valid node
		if(verdict != null)
		{
			if(verdict.data == value)
				return true;
			else
				return false;
		}
		// If its null, we did not find the value
		else
			return false;
		
	}
	
	/**
	 * Method to search for a value in the tree recursively
	 * 
	 * @param root				The root
	 * @param value				The value to search for 
	 * @return					True or false, in tree or not
	 */
	private Node isInTree1(Node root, int value)
	{
		// If the value was found, or not found return the node
		if(root == null || root.data == value)
			return root;
		
		// If the value is less than the node, traverse to left
		if(root.data > value)
			return isInTree1(root.left, value);
		// If the value is greater than the node, traverse to right
		else
			return isInTree1(root.right, value);
		
	}
	
	/**
	 * Method to call the minValue method to get the min value of the tree
	 * 
	 * @return				The min value in the tree
	 */
	public int getMin()
	{
		return minValue(root);
	}
	
	/**
	 * Method to call the getMax1 method to find the max value in the tree
	 * 
	 * @return			The max value in the tree
	 */
	public int getMax()
	{
		return getMax1(root);
	}
	
	/**
	 * Method to find the max value in the tree
	 * 
	 * @param root			The root
	 * @return				The max value in the tree
	 */
	private int getMax1(Node root)
	{
		int max = root.data;
		
		// Traverse to the right until cant anymore
		while(root.right != null)
		{
			max = root.right.data;
			root = root.right;
		}
		
		return max;
	}
	
	/**
	 * Method to call the getHeight1 method
	 * 
	 * @return				The height of the tree
	 */
	public int getHeight()
	{
		return getHeight1(root);
	}
	
	/**
	 * Method to recursively find the height of the tree
	 * 
	 * @param root			The root
	 * @return				The height of the tree
	 */
	private int getHeight1(Node root)
	{
		// If there is no node, return 0 (base case)
		if(root == null)
			return 0;
		
		// If there is a node, return the sum of this node plus the height of the node with the max height
		return 1 + Math.max(getHeight1(root.left), getHeight1(root.right));
	}
	
	
}
