package hot100;

import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

/**
 * 字符串解码
 */
public class Q394 {
    public String decodeString(String s) {
        int multi = 0;
        String res = "";
        // 利用两个栈(列表)实现, 一个存储重复次数, 一个存储部分结果字符串
        LinkedList<Integer> count_stk = new LinkedList<>();
        LinkedList<String> res_stk = new LinkedList<>();

        // 遍历字符串
        for (char c : s.toCharArray()) {
            // 如果是数字, 添加到重复次数中
            if (Character.isDigit(c)) {
                multi = multi * 10 + (c - '0');
            } else if (c == '[') {
                // 如果是左括号则入栈
                count_stk.addLast(multi);
                res_stk.addLast(res);
                // 并重置
                multi = 0;
                res = "";
            } else if (c == ']') {
                // 如果是右括号则出栈并拼接字符串
                int num = count_stk.removeLast();
                String str = res_stk.removeLast();
                for (int i = 0; i < num; i++) {
                    str += res;
                }
                res = str;  // 更新结果字符串
            } else {
                res += c;
            }
        }

        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入编码字符串: ");
        String s = scanner.nextLine();
        Q394 solution = new Q394();
        String result = solution.decodeString(s);
        System.out.println("解码后的字符串: " + result);
    }
}
