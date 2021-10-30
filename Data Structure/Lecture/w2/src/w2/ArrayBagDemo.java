import java.util.Arrays;
public class ArrayBagDemo {
	public static void main(String[] args) {
		Bag<String> shoppingBag = new ArrayBag<String>(10);
		shoppingBag.add("Brussels sprout");
		shoppingBag.add("tofu");
		shoppingBag.add("water");
		shoppingBag.add("Brussels sprout");
		shoppingBag.add("tofu");
		shoppingBag.add("tofu");
		shoppingBag.add("yogurt");
		shoppingBag.add("water");
		System.out.println("Is the shopping bag full? " + shoppingBag.isFull());
		System.out.println("I have "+ shoppingBag.getFrequencyOf("water")+ " bottles of water");
		System.out.println("The shopping bag has "+ shoppingBag.getCurrentSize()+" items.");
		System.out.println("I have "+Arrays.toString(shoppingBag.toArray()));
		System.out.println("Do I have yogurt?" + shoppingBag.contains("yogurt"));
		System.out.println("I get "+shoppingBag.remove() + " from the shopping bag.");
		if(shoppingBag.remove("tofu")) System.out.println("I got tofu");
		else System.out.println("The bag may have tofu");
		System.out.println("I have "+Arrays.toString(shoppingBag.toArray()));
		shoppingBag.clear();
		System.out.println("After clearing, is the shopping bag empty?"+shoppingBag.isEmpty());
	}
}
