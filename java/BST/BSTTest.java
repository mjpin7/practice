import java.util.Scanner;

public class BSTTest {
	
	public static void main(String[] args)
	{
		BinarySearchTree myBST = new BinarySearchTree();
		Scanner in = new Scanner(System.in);
		boolean exit = false;
		
		// Input loop
		while(!exit)
		{
			System.out.println("What would you like to do?");
			System.out.println("1. Insert into BST");
			System.out.println("2. Delete a value in BST");
			System.out.println("3. Find the minimum value in the BST");
			System.out.println("4. Find the maximum value in the BST");
			System.out.println("5. Check if a value is in the BST");
			System.out.println("6. Print the tree in \"In-Order\" traversal");
			System.out.println("7. Get height of the tree");
			System.out.println("8. Exit");
			int input = in.nextInt();
			System.out.println();
			
			switch(input)
			{
				case 1:
					System.out.println("***** INSERT VALUE *****");
					System.out.print("What value would you like to insert?: ");
					input = in.nextInt();
					myBST.insert(input);
					
					System.out.println("Value " + input + " inserted!");
					System.out.println();
					break;
				case 2:
					System.out.println("***** DELETE VALUE *****");
					System.out.print("What value would you like to delete?: ");
					input = in.nextInt();
					myBST.delete(input);
					System.out.println();
					break;
				case 3:
					System.out.println("***** MINIMUM VALUE *****");
					System.out.println("The minimum value in the BST is " + myBST.getMin());
					System.out.println();
					break;
				case 4:
					System.out.println("***** MAXIMUM VALUE *****");
					System.out.println("The maximum value in the BST is " + myBST.getMax());
					System.out.println();
					break;
				case 5:
					System.out.println("***** SEARCH FOR VALUE *****");
					System.out.print("What value would you like to check for?: ");
					input = in.nextInt();
					
					if(myBST.isInTree(input))
					{
						System.out.println("Value " + input + " is in the tree");
					}
					else
					{
						System.out.println("Value " + input + " is not in the tree");
					}
					System.out.println();
					break;
				case 6:
					System.out.println("***** PRINT IN-ORDER *****");
					myBST.inOrder();
					System.out.println();
					System.out.println();
					break;
				case 7:
					System.out.println("***** GET HEIGHT *****");
					System.out.println("The height of the tree is " + myBST.getHeight());
					System.out.println();
					break;
				case 8:
					System.out.println("***** EXIT *****");
					System.out.println("Goodbye!");
					exit = true;
					break;
				default:
					System.out.println("Invalid input");
					break;
					
			}
		}
		
		in.close();
	}

}
