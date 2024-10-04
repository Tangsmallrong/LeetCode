package hot100;

import java.util.Arrays;
import java.util.Scanner;

/**
 * 分割等和子集
 * 动规
 */
public class Q416 {
    public boolean canPartition(int[] nums) {
        // 计算数组总和
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        // 如果总和是奇数则直接返回 false
        if (sum % 2 != 0) {
            return false;
        }

        // 抽象为背包问题, 一维dp数组
        int target = sum / 2;
        int[] dp = new int[target + 1];

        // 初始化
        Arrays.fill(dp, 0);

        // 遍历, 先物品后背包(背包倒序遍历)
        for (int i = 0; i < nums.length; i++) {
            // 数组元素数值既是物品重量也是价值
            for (int j = target; j >= nums[i]; j--) {
                // 递推公式
                dp[j] = Math.max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        // 当容量为 target 时, 能装的最大价值也是 target, 说明可以划分
        return dp[target] == target;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        String[] split = str.split("\\s+");
        int[] nums = new int[split.length];

        for (int i = 0; i < nums.length; i++) {
            nums[i] = Integer.parseInt(split[i]);
        }

        Q416 solution = new Q416();
        boolean res = solution.canPartition(nums);
        System.out.println(res);
    }
}
