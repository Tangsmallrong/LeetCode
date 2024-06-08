package hot100;

import java.util.Arrays;
import java.util.Scanner;

/**
 * 轮转数组
 */
public class Q189 {
    public void rotate(int[] nums, int k) {
        // 先对 k 取余, 防止其超出数组长度
        k %= nums.length;

        // 利用3次翻转代替轮转, Java 没有直接提供用于反转数组的方法
        // 要么将数组转换为 List，然后使用 Collections.reverse 反转 List
        // 要么手动编写方法反转数组, 如下:
        reverse(nums, 0, nums.length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.length - 1);
    }

    // 反转数组
    private void reverse(int[] nums, int start, int end) {
        while (start < end) {  // 头尾指针
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入数组的长度
        System.out.println("请输入数组的长度: ");
        int n = scanner.nextInt();

        // 初始化数组
        int[] nums = new int[n];
        System.out.println("请输入数组元素: ");
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }

        // 输入轮转的次数
        System.out.println("请输入轮转的次数: ");
        int k = scanner.nextInt();

        Q189 q189 = new Q189();
        q189.rotate(nums, k);

        // 输出结果
        System.out.println("轮转后的数组为: " + Arrays.toString(nums));

        scanner.close();
    }
}
