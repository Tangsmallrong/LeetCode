package hot100;

import java.util.Scanner;

/**
 * 在排序数组中查找元素的第一个和最后一个位置
 */
public class Q34 {
    public int[] searchRange(int[] nums, int target) {
        // 使用闭区间写法
        int left = 0;
        int right = nums.length - 1;

        // 结果数组
        int[] res = {-1, -1};

        // 二分查找: 查找元素的第一个位置
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // 判断数组中是否存在该目标元素
        if (left < nums.length && nums[left] == target) {
            res[0] = left;
        } else {
            return res;
        }

        // 二分查找: 查找元素的最后一个位置
        right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        res[1] = right;
        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入数组长度和数组元素
        System.out.println("请输入数组的长度: ");
        int n = scanner.nextInt();

        // 初始化数组
        int[] nums = new int[n];
        System.out.println("请输入数组元素: ");
        for (int i = 0; i < n; ++i) {
            nums[i] = scanner.nextInt();
        }

        // 输入目标值
        System.out.println("请输入目标值: ");
        int target = scanner.nextInt();

        Q34 solution = new Q34();
        int[] result = solution.searchRange(nums, target);

        // 输出结果
        System.out.println("目标值的起始位置和结束位置为: [" + result[0] + ", " + result[1] + "]");

        scanner.close();
    }
}
