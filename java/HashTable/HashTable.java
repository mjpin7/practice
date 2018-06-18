/**
 * HashTable class. Implemented with array and linear probing
 * 
 * @author MPinheiro
 *
 */
public class HashTable {
	
	private int size, capacity;				// Size and capacity
	private Pair[] table;					// The array of pairs
	
	/* CONSTRUCTOR */
	public HashTable(int cap)
	{
		this.capacity = cap;
		this.size = 0;
		this.table = new Pair[cap];
		
		for(int i = 0; i < cap; i++)
		{
			this.table[i] = null;
		}
	}
	
	/**
	 * Method to get the size of the table
	 * 
	 * @return			The size of the table
	 */
	public int sizeTable()
	{
		return this.size;
	}
	
	/**
	 * Method to check if the table is full
	 * 	
	 * @return			True or false, full or not
	 */
	public boolean isFull()
	{
		if(this.size == this.capacity)
			return true;
		
		return false;
	}
	
	/**
	 * Method to get the hash code for inserting (Linearly probe until found one that is free)
	 * 
	 * @param key			The key to hash
	 * @return				The hash 
	 */
	public int hash(String key)
	{
		int total = 0;
		for(int i = 0; i < key.length(); i++)
		{
			total += key.charAt(i);
		}
		
		int hash = total % capacity;
		
		// Linearly probe
		while(table[hash] != null)
		{
			hash = (hash + 1) % capacity;
		}
		
		return hash;
		
	}
	
	/**
	 * Method to get the hash of a key (used for getting the hash of an already created key)
	 * 
	 * @param key				The key to hash
	 * @return					The hash, or -1 if not found
	 */
	public int hash1(String key)
	{
		int total = 0;
		for(int i = 0; i < key.length(); i++)
		{
			total += key.charAt(i);
		}
		
		int hash = total % this.capacity;
		int n = 0;
		
		// Linearly probe until the end or found the key
		while(table[hash] != null && table[hash].getKey().compareTo(key) != 0)
		{
			hash = (hash + 1) % this.capacity;
			
			if(n == this.capacity)
				break;
			
			n++;
		}
		
		if(table[hash].getKey().compareTo(key) == 0)
		{
			return hash;
		}
		else
		{
			return -1;
		}
	}
	
	/**
	 * Method to insert a key/value pair in the table
	 * 
	 * @param key				The key of the pair
	 * @param value				The value of the pair
	 */
	public void insert(String key, String value)
	{
		if(!isFull())
		{
			int hash = this.hash(key);
			
			table[hash] = new Pair(key, value);
			System.out.println("Value " + value + " at key " + key + " added.");
			this.size++;
		}
		else
		{
			System.out.println("Table Full");
		}
	}
	
	/**
	 * Method to remove a pair from the table from a certain key
	 * 
	 * @param key			The key of the pair to remove
	 */
	public void remove(String key)
	{
		int hash = hash1(key);
		
		if(hash >= 0)
		{
			System.out.println("Key " + key + " with value " + table[hash].getValue() + " removed.");
			table[hash] = null;
			this.size--;
		}
		else
		{
			System.out.println("Key " + key + " not found.");
		}
		
	}
	
	/**
	 * Method to get a value from a certain key
	 * 
	 * @param key			The key to search for
	 * @return				The value of the key, or null if not found
	 */
	public String get(String key)
	{
		int hash = hash1(key);
		
		if(hash >= 0)
		{
			return table[hash].getValue();
		}
		else
		{
			System.out.println("Key " + key + " not found.");
			return null;
		}
	}
	
	/**
	 * Method to print the table out
	 */
	public void printTable()
	{
		System.out.println();
		System.out.println();
		System.out.println("Table:");
		for(int i = 0; i < this.capacity; i++)
		{
			if(table[i] != null)
			{
				System.out.println("Key: " + table[i].getKey() + " Value: " + table[i].getValue());
			}
		}
		System.out.println();
		System.out.println();
	}

}

/**
 * Class for a pair
 * 
 * @author MPinheiro
 *
 */
class Pair
{
	private String key;					// The key of the pair
	private String value;				// The value of the pair
	
	/* CONSTRUCTOR */
	public Pair(String key, String val)
	{
		this.key = key;
		this.value = val;
	}
	
	/**
	 * Method to get the key
	 * 
	 * @return			The key
	 */
	public String getKey()
	{
		return this.key;
	}
	
	/**
	 * Method to get the value
	 * 
	 * @return			The value
	 */
	public String getValue()
	{
		return this.value;
	}
}
