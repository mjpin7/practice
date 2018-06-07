/**
 * Class for testing the linked list class
 * 
 * @author MPinheiro
 *
 */
public class ListTester {
	
	public static void main(String[] args)
	{
		LinkedList<Integer> myList = new LinkedList<Integer>();
		
		System.out.println(myList.empty());
		myList.push_front(2);
		System.out.println("Value at index 0: " + myList.value_at(0));
		System.out.println(myList.empty());
		System.out.println("Popped front: " + myList.pop_front());
		System.out.println(myList.empty());
		myList.push_back(9);
		myList.push_back(13);
		myList.printList();
		myList.insert(1, 34);
		myList.printList();
		System.out.println(myList.erase(2));
		myList.printList();
		System.out.println(myList.erase(1));
	}

}
