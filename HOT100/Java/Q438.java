package hot100;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

/**
 * 找到字符串中的所有字母异位词
 */
public class Q438 {
    public List<Integer> findAnagrams(String s, String p) {
        // 创建 map 分别存储当前窗口内字符出现次数和目标字符串中每个字符的出现次数
        HashMap<Character, Integer> win = new HashMap<>();
        HashMap<Character, Integer> need = new HashMap<>();
        List<Integer> res = new ArrayList<>();  // 存储返回结果

        // 将目标字符串的字符及其出现次数存储至 map 中
        for (char c : p.toCharArray()) {
            need.put(c, need.getOrDefault(c, 0) + 1);
        }

        // 双指针滑动窗口遍历字符串
        int left = 0, right = 0;
        int count = 0;
        while (right < s.length()) {
            char c = s.charAt(right);
            right++;

            // 判断目标字符串中是否存在该字符
            if (need.containsKey(c)) {
                // 存在则更新滑动窗口中对应字符的出现次数
                win.put(c, win.getOrDefault(c, 0) + 1);

                // 注意这里的 Integer 属于对象间的比较, 如果不在缓存范围内则需要用 equals 方法比较
                if (need.get(c).equals(win.get(c))) {
                    count++;
                }
            }

            // 判断是否需要更新窗口的左边界, 注意此处是 p 的长度(p.length() != need.size() 因为可能会有重复的字符)
            while (right - left >= p.length()) {
                // 判断当前滑动窗口内的字符是否符合条件, 注意此处是 need 的长度
                if (count == need.size()) {
                    res.add(left);
                }

                char d = s.charAt(left);
                left++;

                // 判断原来左边界的字符是否存在于目标字符串中
                if (need.containsKey(d)) {
                    if (need.get(d).equals(win.get(d))) {
                        count--;
                    }
                    win.put(d, win.get(d) - 1);
                }
            }
        }

        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入第一个字符串
        System.out.println("请输入第一个字符串（回车结束）: ");
        String s = scanner.nextLine();

        // 输入第二个字符串
        System.out.println("请输入第二个字符串（回车结束）: ");
        String p = scanner.nextLine();

        // 调用 findAnagrams 方法
        Q438 q438 = new Q438();
        List<Integer> result = q438.findAnagrams(s, p);

        // 输出结果
        System.out.println("结果索引为: ");
        for (int index : result) {
            System.out.print(index + " ");
        }
        System.out.println();

        scanner.close();
    }
}
