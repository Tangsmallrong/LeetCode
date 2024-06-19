package hot100;

import java.util.Scanner;

/**
 * 搜索旋转排序数组
 */
public class Q33 {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;

        // 二分查找
        // 寻找旋转点位置, 旋转点前的数都大于旋转点后的数
        while (left <= right) {
            int mid  = left + (right - left) / 2;

            // 如果中间值大于等于数组的第一个值，说明旋转点在右边
            if (nums[mid] >= nums[0]) {
                left = mid + 1;  // 搜索范围缩小到右边部分
            } else {
                right = mid - 1;  // 搜索范围缩小到左边部分
            }
        }

        // 确定搜索范围为旋转点的左区间还是右区间
        if (target >= nums[0]) {
            left = 0;
        } else {
            right = nums.length - 1;
        }

        // 在搜索范围里对目标值进行二分查找
        while (left <= right) {
            int mid  = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入旋转排序数组
        System.out.println("请输入旋转排序数组（例如：4 5 6 7 0 1 2）：");
        String[] input = scanner.nextLine().split(" ");
        int[] nums = new int[input.length];
        for (int i = 0; i < input.length; i++) {
            nums[i] = Integer.parseInt(input[i]);
        }

        // 输入目标值
        System.out.println("请输入目标值：");
        int target = scanner.nextInt();

        Q33 solution = new Q33();
        int result = solution.search(nums, target);

        // 输出结果
        if (result != -1) {
            System.out.println("目标值在数组中的索引为：" + result);
        } else {
            System.out.println("目标值不在数组中");
        }

        scanner.close();
    }
}
