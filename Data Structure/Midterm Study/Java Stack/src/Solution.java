import java.util.*;
class Solution{
	
	public static void main(String []argh)
	{
		Scanner sc = new Scanner(System.in);
		
		while (sc.hasNext()) {
			String input=sc.next();
            //Complete the code
			Stack<String> stack = new Stack<String>();
			boolean answer = true;
			
			int len = input.length()-1;
			
			for(int i=len; i>=0; i--) {
				String target = input.substring(i, i+1);
				
				if(target.equals(")")|| target.equals("}") || target.equals("]")) {
					stack.push(target);
				}
				else {
					if (stack.isEmpty()) {
						answer = false;
						stack.empty();
						break;
					}
					else {
						String partner = stack.pop();
						if (target.equals("[")) {
							if(!partner.equals("]")) {
								answer = false;
								stack.empty();
								break;
							}
						}
						else if(target.equals("{")) {
							if(!partner.equals("}")) {
								answer = false;
								stack.empty();
								break;
							}
						}
						else if(target.equals("(")) {
							if(!partner.equals(")")) {
								answer = false;
								stack.empty();
								break;
							}
						}
					}
				}
			}
			
			if(!stack.isEmpty()) {
				answer = false;
				stack.empty();
			}
			
			if(answer) {
				System.out.println("true");
			}else {
				System.out.println("false");
			}
			
			
			
		}
		
	}
}



//undefined