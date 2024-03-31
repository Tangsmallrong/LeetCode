package array;

import java.util.Scanner;

/**
 * 有序数组的平方
 * 双指针
 *
 * @author thr
 */
public class Q977 {
    public int[] sortedSquares(int[] nums) {
        int len = nums.length;
        int k = len - 1, i = 0, j = k;
        int[] result = new int[len];

        while (i <= j) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                result[k--] = nums[i] * nums[i];
                i++;
            } else {
                result[k--] = nums[j] * nums[j];
                j--;
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入数组
        System.out.print("请输入有序(非递减顺序)数组（以空格分隔，回车结束）: ");  // -5 -3 1 2 6
        String line = scanner.nextLine();
        String[] numsStr = line.split(" ");
        int[] nums = new int[numsStr.length];
        for (int i = 0; i < numsStr.length; i++) {
            nums[i] = Integer.parseInt(numsStr[i]);
        }

        Q977 q977 = new Q977();
        int[] result = q977.sortedSquares(nums);

        // 输出平方后的数组
        System.out.print("平方后的数组（非递减顺序）: ");  // 1 4 9 25 36
        for (int num : result) {
            System.out.print(num + " ");
        }
        System.out.println();

        scanner.close();
    }
}
