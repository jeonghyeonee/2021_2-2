import java.util.*;
public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		Deque deque = new LinkedList<>();
		int n = in.nextInt();
		int m = in.nextInt();
		
		Set set = new HashSet<Integer>();
		int max = 0;


		for (int i = 0; i < n; i++) {
            int num = in.nextInt();
            deque.add(num);
            set.add(num);

            if (deque.size() == m) {
                max = Math.max(max, set.size());
                int pollNum = (int) deque.poll();
                if (!deque.contains(pollNum)) {
                    set.remove(pollNum);
                }
            }
        }
        System.out.println(max);
		
		
	}
}



//undefined