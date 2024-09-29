package hot100;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * 子集
 * 回溯
 */
public class Q78 {
    private final List<Integer> path = new ArrayList<>();
    private final List<List<Integer>> res = new ArrayList<>();

    public List<List<Integer>> subsets(int[] nums) {
        if (nums.length == 0) return res;

        res.add(path);  // 空集
        // 递归
        backTracking(nums, 0);
        return res;
    }

    private void backTracking(int[] nums, int startIndex) {
        // 递归终止条件(可以省略)
        if (startIndex >= nums.length) {
            return;
        }

        // 单层递归逻辑
        for (int i = startIndex; i < nums.length; i++) {
            path.add(nums[i]);

            // 也可以在递归函数开始的时候就将path添加到结果集中, 就不用特殊处理空集了
            res.add(new ArrayList<>(path));

            // 递归
            backTracking(nums, i + 1);

            // 回溯
            path.remove(path.size() - 1);
        }

        return;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        String[] values = str.split("\\s+");
        int[] nums = new int[values.length];

        for (int i = 0; i < nums.length; i++) {
            nums[i] = Integer.parseInt(values[i]);
        }

        Q78 solution = new Q78();
        List<List<Integer>> result = solution.subsets(nums);

        for (List<Integer> res : result) {
            for (Integer num : res) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }
}
