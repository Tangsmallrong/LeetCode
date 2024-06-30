package hot100;

import java.util.Stack;

/**
 * 最小栈
 */
public class Q155 {
    public static void main(String[] args) {
        MinStack minStack = new MinStack();
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);

        System.out.println("当前最小值: " + minStack.getMin()); // 返回 -3
        minStack.pop();
        System.out.println("堆栈顶部元素: " + minStack.top()); // 返回 0
        System.out.println("当前最小值: " + minStack.getMin()); // 返回 -2
    }
}

class MinStack {
    private final Stack<int[]> stack = new Stack<>();

    // 入栈
    public void push(int val) {
        // 若栈空, 则直接push
        if (stack.empty()) {
            stack.push(new int[] {val, val});
        } else {  // 非空则push当前元素与栈中最小值中的较小者
            stack.push(new int[] {val, Math.min(val, getMin())});
        }
    }

    // 出栈
    public void pop() {
        stack.pop();
    }

    // 获取栈顶元素
    public int top() {
        return stack.peek()[0];
    }

    // 获取栈中最小元素
    public int getMin() {
        return stack.peek()[1];
    }
}
