package hot100;

import java.util.Scanner;

/**
 * 打家劫舍
 * 动态规划
 */
public class Q198 {
    public int rob(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }

        // 定义状态数组, 考虑[0,i]的房间能够偷到的最大金币数量为dp[i]
        int[] dp = new int[nums.length];

        // 初始化, dp[i]依赖于dp[i-1]和dp[i-2]的状态
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);

        // 遍历
        for (int i = 2; i < nums.length; i++) {
            // 分情况讨论, 分别是不偷第i个房间(dp[i - 1])和偷第i个房间(dp[i - 2] + nums[i])
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[nums.length - 1];
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String values = input.nextLine();
        String[] split = values.split("\\s+");
        int[] nums = new int[split.length];

        for (int i = 0; i < nums.length; i++) {
            nums[i] = Integer.parseInt(split[i]);
        }

        Q198 solution = new Q198();
        int res = solution.rob(nums);
        System.out.println(res);
    }
}
