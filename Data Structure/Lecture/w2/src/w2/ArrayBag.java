public class ArrayBag<T> implements Bag<T> {
	private final T[] bag;
	private int numberOfEntries;
	private static final int DEFAULT_CAPACITY = 25;
	private static final int MAX_CAPACITY = 10000;
	private boolean integrityOK;
	public ArrayBag() {
		this(DEFAULT_CAPACITY);
	}
	public ArrayBag(int capacity) {
		integrityOK = false;
		if(capacity < MAX_CAPACITY) {
			@SuppressWarnings("unchecked")
			T[] tempBag = (T[]) new Object[capacity];
			bag = tempBag;
			numberOfEntries = 0;
			integrityOK=true;
		} else
			throw new IllegalStateException("Attempt to create a bag whose"
					+ "capacity exceeds allowed maximum.");
	}
	public int getCurrentSize() {
		return numberOfEntries;
	}
	public boolean isFull() {
		return numberOfEntries>=bag.length;
	}
	public boolean isEmpty() {
		return numberOfEntries==0;
	}
	public boolean add(T newEntry) {
		checkIntegrity();
		if(isFull()) return false;
		else bag[numberOfEntries++]=newEntry;
		return true;
	}
	public T remove() {
		checkIntegrity();
		return removeEntry(numberOfEntries-1);
	}
	public boolean remove(T anEntry) {
		checkIntegrity();
		int index = getIndexOf(anEntry);
		T result = removeEntry(index);
		return anEntry.equals(result);
	}
	public void clear() {
		checkIntegrity();
		while(!isEmpty()) remove();
	}
	public int getFrequencyOf(T anEntry) {
		checkIntegrity();
		int counter = 0;
		for(int i = 0 ; i < numberOfEntries ; i++)
			if(anEntry.equals(bag[i])) counter++;
		return counter;
	}
	public boolean contains(T anEntry) {
		checkIntegrity();
		return getIndexOf(anEntry)>=0;
	}
	public T[] toArray() {
		checkIntegrity();
		@SuppressWarnings("unchecked")
		T[] result = (T[])new Object[numberOfEntries];
		for(int i = 0 ; i < numberOfEntries ;i++)
			result[i]=bag[i]; 
		return result;
	}
	private void checkIntegrity() {
		if(!integrityOK) throw new SecurityException("ArrayBag object is corrupt");
	}
	private T removeEntry(int index) {
		T result = null;
		if(!isEmpty() && (index >= 0)) {
			result = bag[index];
			bag[index]=bag[numberOfEntries-1];
			bag[numberOfEntries-1]=null;
			numberOfEntries--;
		}
		return result;
	}
	private int getIndexOf(T anEntry) {
		int found = -1;
		for(int i = 0 ; found < 0 && i < numberOfEntries ; i++)
			if(anEntry.equals(bag[i])) found = i;
		return found;
		
	}
}
