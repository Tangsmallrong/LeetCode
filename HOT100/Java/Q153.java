package hot100;

import java.util.Scanner;

/**
 * 寻找旋转排序数组中的最小值
 */
public class Q153 {
    public int findMin(int[] nums) {
        // 闭区间写法
        int left = 0;
        int right = nums.length - 1;

        // 寻找旋转点, 旋转点前的数均大于旋转点后的数
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] >= nums[0]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // 检查 left 是否在有效范围内
        return left < nums.length ? nums[left] : nums[0];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入数组长度
        System.out.println("请输入数组的长度: ");
        int n = scanner.nextInt();

        // 初始化数组
        int[] nums = new int[n];
        System.out.println("请输入数组元素: ");
        for (int i = 0; i < n; ++i) {
            nums[i] = scanner.nextInt();
        }

        Q153 q153 = new Q153();
        int result = q153.findMin(nums);

        // 输出结果
        System.out.println("数组中的最小元素是: " + result);

        scanner.close();
    }
}
