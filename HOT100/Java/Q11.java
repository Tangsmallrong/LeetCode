package hot100;

import java.util.Scanner;

/**
 * 盛最多水的容器
 */
public class Q11 {
    public int maxArea(int[] height) {
        // 定义头尾双指针
        int l = 0;
        int r = height.length - 1;
        int area = 0;


        // 遍历数组, 直到两指针相遇
        while (l < r) {
            // 计算当前盛水面积, 判断是否需要更新当前最大面积
            area = Math.max(area, Math.min(height[l], height[r]) * (r - l));

            // 移动双指针
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return area;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入数组的长度
        System.out.println("请输入数组的长度: ");
        int n = scanner.nextInt();

        // 初始化数组
        int[] height = new int[n];
        System.out.println("请输入数组元素，以空格分隔: ");
        for (int i = 0; i < n; i++) {
            height[i] = scanner.nextInt();
        }

        Q11 solution = new Q11();
        int result = solution.maxArea(height);

        // 输出结果
        System.out.println("可以容纳的最大水量为: " + result);

        scanner.close();
    }
}
