package hot100;

import java.util.HashMap;
import java.util.Scanner;
import java.util.Stack;

/**
 * 有效的括号
 */
public class Q20 {
    public boolean isValid(String s) {
        // 剪枝
        if (s.length() % 2 != 0) {
            return false;
        }

        // 使用 map 存储括号的对应关系
        HashMap<Character, Character> map = new HashMap<>();
        map.put(')', '(');  // 注意将右括号作为键, 方便后续匹配查找
        map.put('}', '{');
        map.put(']', '[');

        // 栈
        Stack<Character> st = new Stack<>();

        // 遍历字符串
        for (char c : s.toCharArray()) {
            // 左括号直接入栈
            if (map.containsValue(c)) {
                st.push(c);
            } else if (!st.empty() && st.peek().equals(map.get(c))) {
                // 如果栈不为空, 且右括号成功匹配, 则弹出栈顶元素
                st.pop();
            } else {
                // 如果匹配中途栈空了或右括号无法成功匹配, 直接返回 false
                return false;
            }
        }

        return st.empty();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入字符串: ");
        String s = scanner.nextLine();

        Q20 solution = new Q20();
        boolean result = solution.isValid(s);
        System.out.println("输入字符串是否有效: " + result);
    }
}
