package hot100;

import java.util.Arrays;
import java.util.Scanner;

/**
 * 最长递增子序列
 * 动态规划
 */
public class Q300 {
    public int lengthOfLIS(int[] nums) {
        // 定义dp数组, dp[i]表示以nums[i]为结尾的最长递增子序列
        int[] dp = new int[nums.length];

        // 初始化, 认为只有1个数时结果为1
        Arrays.fill(dp, 1);

        int res = 1;
        // 外层循环遍历nums[i]
        for (int i = 1; i < nums.length; i++) {
            // 内层循环遍历(0,i), 计算以nums[i]为结尾的最长递增子序列的长度
            for (int  j = 0; j < i; j++) {
                // 判断nums[j]是否小于nums[i]
                if (nums[j] < nums[i]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }

            // 记录最长递增子序列的长度
            res = Math.max(res, dp[i]);
        }

        return res;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String values = input.nextLine();
        String[] split = values.split("\\s+");
        int[] nums = new int[split.length];

        for (int i = 0; i < nums.length; i++) {
            nums[i] = Integer.parseInt(split[i]);
        }

        Q300 solution = new Q300();
        int res = solution.lengthOfLIS(nums);
        System.out.println(res);
    }
}
