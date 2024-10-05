package hot100;

import java.util.Arrays;
import java.util.Scanner;

/**
 * 零钱兑换
 * 动态规划
 */
public class Q322 {
    public int coinChange(int[] coins, int amount) {
        // 定义dp数组, 凑成目标值amount所用的最少钱币数量即为dp[amount]
        int[] dp = new int[amount + 1];

        // 初始化
        // 非零下标初始化为 int 的最大值, 题意求最少钱币数, 防止覆盖计算结果
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;

        // 遍历, 先物品或先背包都可以, 都是正序(完全背包)
        for (int i = 0; i < coins.length; i++) {
            for (int j = coins[i]; j <= amount; j++) {
                // 如果dp[j - coins[i]]是初始值则跳过
                if (dp[j - coins[i]] != Integer.MAX_VALUE) {
                    dp[j] = Math.min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }

        if (dp[amount] == Integer.MAX_VALUE) {
            return -1;
        }

        return dp[amount];
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        int amount = input.nextInt();
        String[] split = str.split("\\s+");
        int[] coins = new int[split.length];

        for (int i = 0; i < coins.length; i++) {
            coins[i] = Integer.parseInt(split[i]);
        }

        Q322 solution = new Q322();
        int res = solution.coinChange(coins, amount);
        System.out.println(res);
    }
}
