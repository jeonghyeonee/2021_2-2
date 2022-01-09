import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'powerSum' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER X
     *  2. INTEGER N
     */

    public static int powerSum(int X, int N) {
        // Write your code here
        int max = (int) Math.pow(X, 1/(double)N);
        ArrayList<Integer> list = new ArrayList<>();

        for (int i=1; i<= max; i++) {
            list.add((int) Math.pow(i, N));
        }

        int[] dp = new int[X+1];
        dp[0] = 1;

        for (int i=0; i<list.size(); i++) {
            int now = list.get(i);

            for (int j=X-now; j >= 0; j--) {
                if (dp[j] != 0) {
                    dp[j+now] += dp[j];
                }
            }
        }

        return dp[X];

    }

}

public class Test {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int X = Integer.parseInt(bufferedReader.readLine().trim());

        int N = Integer.parseInt(bufferedReader.readLine().trim());

        int result = Result.powerSum(X, N);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
