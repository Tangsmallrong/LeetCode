package hot100;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

/**
 * 柱状图中最大的矩形
 * 单调栈
 */
public class Q84 {
    public int largestRectangleArea(int[] heights) {
        // 定义栈和最大面积
        Deque<Integer> stk = new LinkedList<>();
        int res = 0;

        // 在数组首尾插入0
        int[] arr = new int[heights.length + 2];
        arr[0] = 0;
        arr[heights.length + 1] = 0;
        System.arraycopy(heights, 0, arr, 1, heights.length);

        // 遍历数组
        stk.push(0);
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] >= arr[stk.peek()]) {
                stk.push(i);
            } else {
                while (!stk.isEmpty() && arr[i] < arr[stk.peek()]) {
                    int mid = stk.peek();
                    stk.pop();

                    if (!stk.isEmpty()) {
                        int h = arr[mid];
                        int w = i - stk.peek() - 1;
                        res = Math.max(h * w, res);
                    }
                }
                stk.push(i);
            }
        }

        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入柱子的数量：");
        int n = scanner.nextInt();
        int[] heights = new int[n];
        System.out.println("请输入柱子的高度：");
        for (int i = 0; i < n; i++) {
            heights[i] = scanner.nextInt();
        }

        Q84 solution = new Q84();
        int result = solution.largestRectangleArea(heights);
        System.out.println("最大矩形面积为：" + result);
    }
}
