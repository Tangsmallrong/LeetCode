package hot100;

import java.util.Scanner;
import java.util.Stack;

/**
 * 每日温度
 * 单调栈
 */
public class Q739 {
    public int[] dailyTemperatures(int[] temperatures) {
        // 定义栈和结果数组
        Stack<Integer> stk = new Stack<>();
        int[] res = new int[temperatures.length];  // 创建一个长度为 length 的 int 数组，默认值为 0

        // 注意先把下标0先入栈
        stk.push(0);
        // 遍历气温数组
        for (int i = 1; i < temperatures.length; i++) {
            if (temperatures[i] <= temperatures[stk.peek()]) {
                stk.push(i);
            } else {
                while (!stk.empty() && temperatures[i] > temperatures[stk.peek()]) {
                    res[stk.peek()] = i - stk.peek();
                    stk.pop();
                }
                stk.push(i);
            }
        }

        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 读取温度数组的长度
        System.out.println("请输入温度数组的长度：");
        int length = scanner.nextInt();

        // 创建并读取温度数组
        int[] temperatures = new int[length];
        System.out.println("请输入温度数组的元素：");
        for (int i = 0; i < length; i++) {
            temperatures[i] = scanner.nextInt();
        }

        // 创建 DailyTemperatures 实例并调用方法
        Q739 q739 = new Q739();
        int[] result = q739.dailyTemperatures(temperatures);

        // 打印结果数组
        System.out.println("每天等待的天数：");
        for (int res : result) {
            System.out.print(res + " ");
        }
    }
}
