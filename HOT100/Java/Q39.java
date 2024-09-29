package hot100;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * 组合总和
 * 回溯
 */
public class Q39 {
    private final List<Integer> path = new ArrayList<>();  // 单个结果
    private final List<List<Integer>> res = new ArrayList<>();  // 存储结果集合

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if (candidates.length == 0) return res;

        // 递归
        backTracking(candidates, target, 0, 0);
        return res;
    }

    private void backTracking(int[] candidates, int target, int sum, int startIndex) {
        // 递归终止条件
        if (sum >= target) {
            if (sum == target) {
                res.add(new ArrayList<>(path));  // 添加独立的路径副本, 确保不共享引用
            }
            return;
        }

        // 单层递归逻辑
        for (int i = startIndex; i < candidates.length; i++) {
            path.add(candidates[i]);
            sum += candidates[i];

            // 递归
            // 注意这里 startIndex 参数直接传递 i 而不是 i+1, 因为题目允许同一个数字无限制重复使用
            backTracking(candidates, target, sum, i);

            // 回溯
            sum -= path.get(path.size() - 1);
            path.remove(path.size() - 1);
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        int target = input.nextInt();
        String[] values = str.split("\\s+");

        int[] candidates = new int[values.length];
        for (int i = 0; i < values.length; i++) {
            candidates[i] = Integer.parseInt(values[i]);
        }

        Q39 solution = new Q39();
        List<List<Integer>> res = solution.combinationSum(candidates, target);

        for (List<Integer> path : res) {
            for (Integer num : path) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }
}
