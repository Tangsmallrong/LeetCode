package hot100;

import java.util.*;

/**
 * 括号生成
 * 回溯
 */
public class Q22 {
    private char[] ch;
    private final List<String> res = new ArrayList<>();

    public List<String> generateParenthesis(int n) {
        if (n == 0) return res;

        // 初始化字符数组, 长度为 2*n
        ch = new char[2 * n];
        backTracking(0, 0, 0, n);
        return res;
    }

    private void backTracking(int index, int left, int right, int n) {
        // 递归终止条件, 左右括号相等且为n
        if (left == n && right == n) {
            res.add(new String(ch));
            return;
        }

        // 单层递归逻辑
        // 如果左括号的数量小于 n, 可以选择放一个左括号
        if (left < n) {
            ch[index] = '(';

            // index: 当前字符数组的索引, 用于跟踪放置的括号位置
            backTracking(index + 1, left + 1, right, n);
        }

        // 如果右括号的数量小于左括号的数量, 可以选择放一个右括号
        if (right < left) {
            ch[index] = ')';
            backTracking(index + 1, left, right + 1, n);
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        Q22 solution = new Q22();
        List<String> result = solution.generateParenthesis(n);

        for (String str : result) {
            System.out.println(str);
        }
    }
}
