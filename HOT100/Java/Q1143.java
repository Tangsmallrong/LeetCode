package hot100;

import java.util.Scanner;

/**
 * 最长公共子序列
 * 动态规划
 */
public class Q1143 {
    public int longestCommonSubsequence(String text1, String text2) {
        // 定义dp数组, 默认初始化均为0
        // dp[i][j]表示nums1的[0,i-1]部分和nums2的[0,j-1]部分两个数组的最长公共子序列
        int[][] dp = new int[text1.length() + 1][text2.length() + 1];

        // 遍历两个字符串
        for (int i = 1; i <= text1.length(); i++) {
            for (int j = 1; j <= text2.length(); j++) {
                // 如果当前字符相等
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    // 在 dp[i-1][j-1] 的基础上加1
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // 否则, 取 dp[i-1][j] 和 dp[i][j-1] 中的较大值
                    // 要么舍弃 text1[i-1], 要么舍弃 text2[j-1], 取它们两个状态中较大的一个
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[text1.length()][text2.length()];
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String text1 = input.nextLine();
        String text2 = input.nextLine();

        Q1143 solution = new Q1143();
        int res = solution.longestCommonSubsequence(text1, text2);
        System.out.println(res);
    }
}
