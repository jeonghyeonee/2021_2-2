//https://zoosso.tistory.com/112
import java.util.*;

class Solution{

    public static void main(String []argh)
    {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {

            String str = sc.next();
            Stack<String> stack = new Stack<>();
            boolean answer = true;
            // 끝에서 부터 괄호를 탐색하겠다.
            int idx = str.length() - 1;
            while(idx >= 0){
                String target = str.substring(idx,  idx+1);

                // 닫힌 괄호 형태는 우선 스택에 넣어준다.
                if(target.equals(")") ||  target.equals("}") || target.equals("]")) {

                    stack.push(target);
                }else { // 여는 괄호가 나올 시 스택에서  pop하여 쌍이 맞는지 확읺나다.
                    // 우선 스택이 비어져 있는지 확인한다.
                    if(stack.isEmpty()) {
                        answer = false;
                        stack.empty();
                        break;
                    }else {
                        String partner = stack.pop();
                        if(target.equals("[")) {
                            if(!partner.equals("]")) {
                                // 쌍이 맞지 않으면
                                // 스택을 리셋한다.
                                answer = false;
                                stack.empty();
                                break;
                            }
                        }else if(target.equals("{")) {
                            if(!partner.equals("}")) {
                                answer = false;
                                stack.empty();
                                break;
                            }
                        }else if(target.equals("(")){
                            if(!partner.equals(")")) {
                                answer = false;
                                stack.empty();
                                break;
                            }
                        }
                    }
                }
                idx--;
            }

            // 여는 괄호 없이 닫는 괄호만 있을 수 있다.
            // 탐색이 끝났을 때 스택에 남아 있는 원소 확인
            if(!stack.isEmpty()) {
                answer = false;
                // 다음 탐색을 위해 비워준다.
                stack.empty();
            }

            if(answer){
                System.out.println("true");
            }else{
                System.out.println("false");
            }
        }

    }
}