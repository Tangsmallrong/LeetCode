package hot100;

import java.util.Scanner;

/**
 * 除自身以外数组的乘积
 */
public class Q238 {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        res[0] = 1;

        // 计算前缀积
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        // 计算后缀积并与前缀积相乘
        int suf = 1;
        for (int i = n - 2; i >= 0; i--) {
            suf *= nums[i + 1];
            res[i] *= suf;
        }

        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入数组长度
        System.out.print("请输入数组的长度: ");
        int n = scanner.nextInt();

        // 输入数组元素
        System.out.print("请输入数组元素: ");
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }

        Q238 solution = new Q238();
        int[] result = solution.productExceptSelf(nums);

        // 输出结果
        System.out.print("数组中除自身之外其余各元素的乘积: ");
        for (int val : result) {
            System.out.print(val + " ");
        }
        System.out.println();

        scanner.close();
    }
}
