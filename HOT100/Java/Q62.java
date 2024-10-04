package hot100;

import java.util.Scanner;

/**
 * 不同路径
 * 动规
 */
public class Q62 {
    public int uniquePaths(int m, int n) {
        // 二维 dp 数组
        int[][] dp = new int[m][n];

        // 初始化第一列, 只有一种走法, 一直向下
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        // 初始化第一行, 只有一种走法, 一直向右
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }

        // 遍历数组, 根据状态转移方程(递推公式)计算路径数
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int m = input.nextInt();
        int n = input.nextInt();

        Q62 solution = new Q62();
        int res = solution.uniquePaths(m, n);
        System.out.println(res);
    }
}
