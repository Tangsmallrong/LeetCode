package hot100;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * 电话号码的字母组合
 * 回溯
 */
public class Q17 {
    private final StringBuilder s = new StringBuilder();  // 存储单个结果
    private final List<String> res = new ArrayList<>();  // 存储结果集

    // 定义映射规则, 字符串的下标作为对应的数字
    private final String[] map = {
            "", "",
            "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    public List<String> letterCombinations(String digits) {
        // 当传入字符串为空时直接返回
        if (digits.length() == 0) return res;

        // 利用回溯模拟暴力for求组合
        backTracking(digits, 0);
        return res;
    }

    // 递归函数, index 为当前层递归所对应的数字在数字字符串digits的下标
    private void backTracking(String digits, int index) {
        // 递归终止条件: 处理完数字字符串
        if (index == digits.length()) {
            res.add(s.toString());
            return;
        }

        // 单层递归逻辑
        // 获取当前层需要遍历的字符串
        int digit = digits.charAt(index) - '0';
        String str = map[digit];

        // 遍历字符串
        for (int i = 0; i < str.length(); i++) {
            s.append(str.charAt(i));

            // 递归
            backTracking(digits, index + 1);

            // 回溯
            s.deleteCharAt(s.length() - 1);
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String digits = input.nextLine();

        Q17 solution = new Q17();
        List<String> res = solution.letterCombinations(digits);

        for (String s : res) {
            System.out.println(s);
        }
    }
}
