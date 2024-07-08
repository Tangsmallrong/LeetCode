package hot100;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

/**
 * 接雨水
 * 单调栈
 */
public class Q42 {
    public int trap(int[] height) {
        // 定义栈和存储雨水面积总和的值
        Deque<Integer> stack = new LinkedList<>();
        int sum = 0;

        // 遍历数组
        stack.push(0);
        for (int i = 1; i < height.length; i++) {
            if (height[i] <= height[stack.peek()]) {
                stack.push(i);
            } else {
                while (!stack.isEmpty() && height[i] > height[stack.peek()]) {
                    // 记录当前栈顶元素后再pop
                    int mid = stack.peek();
                    stack.pop();

                    // 再次判断栈是否为空, 不空的情况下计算当前凹槽的面积
                    if (!stack.isEmpty()) {
                        int h = Math.min(height[stack.peek()], height[i]) - height[mid];
                        int w = i - stack.peek() - 1;
                        sum += h * w;
                    }
                }
                stack.push(i);
            }
        }

        return sum;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入数组的长度:");
        int n = scanner.nextInt();
        int[] height = new int[n];
        System.out.println("请输入数组的元素:");
        for (int i = 0; i < n; i++) {
            height[i] = scanner.nextInt();
        }
        Q42 solution = new Q42();
        int result = solution.trap(height);
        System.out.println("可以接的雨水总量: " + result);
    }
}
