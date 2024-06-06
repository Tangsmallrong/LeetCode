package hot100;

import java.util.*;

/**
 * 三数之和
 */
public class Q15 {
    public List<List<Integer>> threeSum(int[] nums) {
        // 对数组进行排序
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();

        // 遍历排序后的数组
        for (int i = 0; i < nums.length; i++) {
            // 剪枝, 最小的数都大于0就直接返回
            if (nums[i] > 0) return res;

            // 对第一个数进行去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // 双指针滑动窗口寻找其他两个数
            int left = i + 1;
            int right = nums.length - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                } else {
                    res.add(Arrays.asList(nums[i], nums[left], nums[right]));

                    // 去重
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    while (left < right && nums[left] == nums[left + 1]) left++;

                    right--;
                    left++;
                }
            }
        }

        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入数组长度
        System.out.println("请输入数组的长度: ");
        int n = scanner.nextInt();

        // 输入数组元素
        int[] nums = new int[n];
        System.out.println("请输入数组元素，以空格分隔: ");
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }

        Q15 q15 = new Q15();
        List<List<Integer>> result = q15.threeSum(nums);

        // 输出结果
        System.out.println("所有和为 0 的三元组为: ");
        for (List<Integer> triplet : result) {
            System.out.println(triplet);
        }

        scanner.close();
    }
}
