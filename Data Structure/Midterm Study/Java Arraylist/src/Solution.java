import java.io.*;
import java.util.*;

import javax.print.attribute.Size2DSyntax;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<ArrayList<Integer>> Array = new ArrayList<ArrayList<Integer>>(n);
        
        for (int i = 0; i<n; i++) {
        	int d = sc.nextInt();
        	ArrayList<Integer> line = new ArrayList<Integer>(d);
        	for (int j=0; j<d; j++) {
        		line.add(sc.nextInt());
        	}
        	Array.add(line);	
        }
        
        int q = sc.nextInt();
        for (int i = 0; i<q; i++) {
        	int x = sc.nextInt();
        	int y = sc.nextInt();
        	
        	if (y > Array.get(x-1).size()) {
        		System.out.println("ERROR!");
        	}
        	else {
        		System.out.println(Array.get(x-1).get(y-1));
        	}
        }
    }
}