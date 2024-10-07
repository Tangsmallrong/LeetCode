package hot100;

import java.util.Scanner;

/**
 * 最大子数组和
 * 动态规划
 */
public class Q53 {
    // 动态规划
    public int maxSubArray(int[] nums) {
        // 定义dp数组, dp[i]表示以nums[i]为结尾的数组的最大子数组的和
        int[] dp = new int[nums.length];

        // 初始化
        dp[0] = nums[0];

        int res = nums[0];
        // 遍历数组
        for (int i = 1; i < nums.length; i++) {
            // 分两种情况, 一种延续前边继续累加, 一种重新开始累加, 取max即可
            dp[i] = Math.max(dp[i - 1] + nums[i], nums[i]);
            res = Math.max(res, dp[i]);
        }

        return res;
    }

    // 贪心解法
    public int maxSubArrayByGreedy(int[] nums) {
        int sum = 0;
        int res = Integer.MIN_VALUE;

        for (int num : nums) {
            sum += num;

            if (sum > res) {
                res = sum;
            }

            // 一旦和小于0就直接抛弃, 将当前累加和置为0, 直接从下一个元素开始重新累加
            if (sum < 0) sum = 0;
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

        Q53 solution = new Q53();
        int res = solution.maxSubArray(nums);
        System.out.println(res);
    }
}
