package array;

import java.util.Scanner;

/**
 * 移除数组元素
 * 快慢指针
 *
 * @author thr
 */
public class Q27 {
    public int removeElement(int[] nums, int val) {
        int slow = 0;

        for (int fast = 0; fast < nums.length; fast++) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
        }

        return slow;
    }

    public static void main(String[] args) {
        int val;
        Scanner scanner = new Scanner(System.in);

        // 输入数组
        System.out.print("请输入数组（以空格分隔，回车结束）: ");
        String line = scanner.nextLine();
        String[] numsStr = line.split(" ");
        int[] nums = new int[numsStr.length];
        for (int i = 0; i < numsStr.length; i++) {
            nums[i] = Integer.parseInt(numsStr[i]);
        }

        // 输入要移除的元素
        System.out.print("请输入要移除的元素: ");
        val = scanner.nextInt();

        Q27 q27 = new Q27();
        int length = q27.removeElement(nums, val);

        // 输出处理后的数组长度
        System.out.println("处理后的数组长度: " + length);

        // 输出处理后的数组内容
        System.out.print("处理后的数组: ");
        for (int i = 0; i < length; i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println();

        scanner.close();
    }
}
