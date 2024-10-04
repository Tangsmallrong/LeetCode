package hot100;

import java.util.Scanner;

/**
 * 爬楼梯
 * 递归
 */
public class Q70 {
    public int climbStairs(int n) {
        if (n == 1) return 1;

        // dp 数组
        int[] dp = new int[n + 1];

        // 初始化
        dp[1] = 1;
        dp[2] = 2;

        // 遍历
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        Q70 solution = new Q70();
        int res = solution.climbStairs(n);
        System.out.println(res);
    }
}
