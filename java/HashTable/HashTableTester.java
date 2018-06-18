
public class HashTableTester {
	public static void main(String[] args)
	{
		HashTable myTable = new HashTable(15);
		myTable.insert("Ontario", "Canada");
		myTable.insert("New York", "USA");
		myTable.insert("Rome", "Italy");
		System.out.println("Size: " + myTable.sizeTable());
		System.out.println("Element at key \"Rome\": " + myTable.get("Rome"));
		myTable.printTable();
		myTable.remove("New York");
		myTable.printTable();
	}

}
