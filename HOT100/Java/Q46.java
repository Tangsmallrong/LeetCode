package hot100;

import java.util.*;

/**
 * 全排列
 * 回溯
 */
public class Q46 {
    List<Integer> path = new ArrayList<>();
    List<List<Integer>> res = new ArrayList<>();

    public List<List<Integer>> permuteUnique(int[] nums) {
        if (nums.length == 0) return res;

        Arrays.sort(nums);
        int[] used = new int[nums.length];
        backTracking(nums, used);
        return res;
    }

    private void backTracking(int[] nums, int[] used) {
        if (path.size() > nums.length) return;
        if (path.size() == nums.length) {
            res.add(new ArrayList<>(path));
        }

        HashSet<Integer> set = new HashSet<>();

        for (int i = 0; i < nums.length; i++) {
            if ((i > 0 && nums[i] == nums[i - 1] && used[i - 1] != 0) || set.contains(nums[i])) {
                continue;
            }

            path.add(nums[i]);
            set.add(nums[i]);
            used[i] = 1;

            // 递归
            backTracking(nums, used);

            // 回溯
            used[i] = 0;
            path.remove(path.size() - 1);
        }
    }

//    public List<List<Integer>> permute(int[] nums) {
//        if (nums.length == 0) return res;
//
//        int[] used = new int[nums.length];
//        backTracking(nums, used);
//        return res;
//    }
//
//    private void backTracking(int[] nums, int[] used) {
//        // 递归终止条件
//        if (path.size() > nums.length) return;
//        if (path.size() == nums.length) {
//            res.add(new ArrayList<>(path));
//            return;
//        }
//
//        // 注意这里是排列, 所以从i=0开始遍历对所有元素, 利用 used 数组防止重复选取同一个元素
//        for (int i = 0; i < nums.length; i++) {
//            if (used[i] != 0) {
//                continue;
//            }
//
//            path.add(nums[i]);
//            used[i] = 1;
//
//            // 递归
//            backTracking(nums, used);
//
//            // 回溯
//            used[i] = 0;
//            path.remove(path.size() - 1);
//        }
//
//        return;
//    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        String[] values = str.split("\\s+");
        int[] nums = new int[values.length];

        for (int i = 0; i < nums.length; i++) {
            nums[i] = Integer.parseInt(values[i]);
        }

        Q46 solution = new Q46();
        List<List<Integer>> result = solution.permuteUnique(nums);

        for (List<Integer> res : result) {
            for (Integer num : res) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }
}
