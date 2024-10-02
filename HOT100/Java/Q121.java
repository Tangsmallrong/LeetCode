package hot100;

import java.util.Scanner;

/**
 * 买卖股票的最佳时机
 * 贪心算法
 */
public class Q121 {
    public int maxProfit(int[] prices) {
        // 初始化成本和利润
        int cost = Integer.MAX_VALUE;
        int profit = 0;

        // 遍历价格序列
        for (int price : prices) {
            // 计算当前的最低买入成本（选择最低的价格买入）
            cost = Math.min(cost, price);
            // 计算当前卖出的最大利润, 并更新
            profit = Math.max(price - cost, profit);
        }

        return profit;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        String[] split = str.split("\\s+");
        int[] prices = new int[split.length];

        for (int i = 0; i < prices.length; i++) {
            prices[i] = Integer.parseInt(split[i]);
        }

        Q121 solution = new Q121();
        int res = solution.maxProfit(prices);
        System.out.println(res);
    }
}
