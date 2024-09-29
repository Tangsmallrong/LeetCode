package hot100;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * 分割字符串
 * 回溯
 */
public class Q131 {
    private final List<String> path = new ArrayList<>();  // 存放切割路径
    private final List<List<String>> res = new ArrayList<>();  // 存放切割的方式结果集

    public List<List<String>> partition(String s) {
        if (s.length() == 0) return res;

        // 递归
        backTracking(s, 0);
        return res;
    }

    private void backTracking(String s, int startIndex) {
        // 递归终止条件
        if (startIndex >= s.length()) {
            res.add(new ArrayList<>(path));
            return;
        }

        // 单层递归逻辑
        for (int i = startIndex; i < s.length(); i++) {
            // 判断当前切割的子串是否回文
            if (!isPalindrome(s, startIndex, i)) {
                // 不是回文串则跳过
                continue;
            }

            // 将该回文子串加入 path 数组
            path.add(s.substring(startIndex, i + 1));

            // 递归
            backTracking(s, i + 1);

            // 回溯
            path.remove(path.size() - 1);
        }
    }

    /**
     * 判断字符串的指定闭区间的子串是否是回文串
     */
    private boolean isPalindrome(String s, int start, int end) {
        int i = start;
        int j = end;

        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String s = input.nextLine();

        Q131 solution = new Q131();
        List<List<String>> result = solution.partition(s);

        for (List<String> res : result) {
            for (String str : res) {
                System.out.print(str + " ");
            }
            System.out.println();
        }
    }
}
