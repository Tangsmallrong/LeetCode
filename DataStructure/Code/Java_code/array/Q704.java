package array;

import java.util.Scanner;

/**
 * 二分查找
 *
 * @author thr
 */
public class Q704 {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target < nums[mid]) {
                right = mid - 1;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                return mid;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        int target;
        Scanner scanner = new Scanner(System.in);

        // 输入数组
        System.out.print("请输入有序数组（以空格分隔，回车结束）: ");
        String line = scanner.nextLine();
        String[] numsStr = line.split(" ");
        int[] nums = new int[numsStr.length];
        for (int i = 0; i < numsStr.length; i++) {
            nums[i] = Integer.parseInt(numsStr[i]);
        }

        // 输入目标值
        System.out.print("请输入目标值: ");
        target = scanner.nextInt();

        Q704 q704 = new Q704();
        int result = q704.search(nums, target);

        // 输出查找结果
        if (result != -1) {
            System.out.println("目标值的索引: " + result);
        } else {
            System.out.println("数组中没有找到目标值");
        }

        scanner.close();
    }
}
