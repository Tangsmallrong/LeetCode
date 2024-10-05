package hot100;

import java.util.Arrays;
import java.util.Scanner;

/**
 * 完全平方数
 * 动态规划
 */
public class Q279 {
    public int numSquares(int n) {
        // 定义 dp 数组, 凑出目标值n至少需要dp[n]个完全平方数
        int[] dp = new int[n + 1];

        // 初始化
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;

        // 遍历
        for (int i = 1; i * i <= n; i++) {
            for (int j = i * i; j <= n; j++) {
                // 一定有解, 因为完全平方数有1
                dp[j] = Math.min(dp[j], dp[j - i * i] + 1);
                // System.out.println(dp[j] + " " + j);
            }
        }

        return dp[n];
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        Q279 solution = new Q279();
        int res = solution.numSquares(n);
        System.out.println(res);
    }
}
