import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();   // 반복문 횟수 입력
        ArrayList<ArrayList<Integer>> Array = new ArrayList<>(n);

        // 초기 배열 선언
        for (int i=0; i<n; i++){
            int l = sc.nextInt();   // 배열 길이 입력
            ArrayList<Integer> line = new ArrayList<>(l);
            for (int j=0; j<l; j++){
                line.add(sc.nextInt());
            }
            Array.add(line);
        }

        int q = sc.nextInt();

        for (int i=0; i<q; i++){
            int x = sc.nextInt();
            int y = sc.nextInt();
            if (Array.get(x-1).size() < y){
                System.out.println("ERROR!");
            }
            else{
                System.out.println(Array.get(x-1).get(y-1));
            }

        }

    }
}