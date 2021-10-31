//https://zoosso.tistory.com/25

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Solution {

    static List<Integer> list;
    static int val, n, answer = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        val = Integer.parseInt(sc.next());
        n = Integer.parseInt(sc.next());
        list = new ArrayList<Integer>();

        int i = 1;
        while(true) {
            if(Math.pow(i, n) >= val) {
                if(Math.pow(i, n) == val) list.add(i);
                break;
            }
            list.add(i);
            i++;
        }

        // 더해지질의 여부, 지금까지의 합산 값, 더해질 원소의 위치
        powerSum(0, 0, 0);
        powerSum(1, 0, 0);

        System.out.println(answer);
    }


    private static void powerSum(int opr, int sum, int idx) {
        // 리스트 범위를 초과하면 조합 X
        if (idx >= list.size()) return;

        // 이번에 고려되는 원소의 거듭 제곱
        int num = (int) Math.pow(list.get(idx), n);

        // 0, 1을 곱해 합산 여부를 결정
        sum = sum + (opr * num);

        // 조합 성공했다면 count
        if(sum == val) {
            answer++;
            return;
        }

        // 목표값을 초과했으면 탐색 종료
        if(sum > val) return;

        // 계속 탐색
        powerSum(0, sum, idx + 1);
        powerSum(1, sum, idx + 1);
    }
}