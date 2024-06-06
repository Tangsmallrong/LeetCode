package hot100;

import java.util.HashMap;
import java.util.Scanner;

/**
 * 无重复字符的最长子串
 */
public class Q3 {
    public int lengthOfLongestSubstring(String s) {
        // 创建 map 用于存储每个元素的上一次出现位置, key 为字符, value 为出现的下标
        HashMap<Character, Integer> map = new HashMap<>();
        int len = 0;
        int j = 0;  // 用于记录滑动窗口的左边界

        // 双指针滑动窗口遍历字符串
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            // 判断当前遍历到的字符的上次出现位置以更新滑动窗口的左边界
            if (map.containsKey(s.charAt(i))) {
                j = Math.max(j, map.get(c) + 1);
            }

            // 更新最长子串的长度
            len = Math.max(len, i - j + 1);

            // 更新所遍历的字符的位置
            map.put(c, i);
        }

        return len;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入字符串
        System.out.println("请输入一个字符串: ");
        String s = scanner.nextLine();

        // 调用 lengthOfLongestSubstring 方法
        Q3 q3 = new Q3();
        int result = q3.lengthOfLongestSubstring(s);

        // 输出结果
        System.out.println("最长不重复子串的长度为: " + result);

        scanner.close();
    }
}
