package hash_table;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

/**
 * 有效的字母异位词
 */
public class Q242 {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        int[] hash = new int[26];

        for (int i = 0; i < s.length(); i++) {
            hash[s.charAt(i) - 'a'] += 1;
        }

        for (int i = 0; i < t.length(); i++) {
            hash[t.charAt(i) - 'a'] -= 1;
        }

        for (int i = 0; i < hash.length; i++) {
            if (hash[i] != 0) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 提示用户输入第一个字符串
        System.out.print("请输入第一个字符串（回车结束）: ");
        String s = scanner.nextLine();

        // 提示用户输入第二个字符串
        System.out.print("请输入第二个字符串（回车结束）: ");
        String t = scanner.nextLine();

        Q242 q242 = new Q242();
        // 调用isAnagram方法，并打印结果
        boolean result = q242.isAnagram(s, t);

        if (result) {
            System.out.println("两个字符串是字母异位词。");
        } else {
            System.out.println("两个字符串不是字母异位词。");
        }

        scanner.close(); // 关闭scanner
    }

    // 集合哈希法
    public boolean isAnagramByHash(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        HashMap<Character, Integer> count = new HashMap<>();

        // 增加 s 中每个字符的计数
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            count.put(c, count.getOrDefault(c, 0) + 1);
        }

        // 减少 t 中每个字符的计数
        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            if (!count.containsKey(c) || count.get(c) == 0) {
                return false;  // 直接返回 false，如果字符不存在或计数为零
            }
            count.put(c, count.get(c) - 1);
        }

        // 检查最后的计数是否所有都为0（可选的，因为前面已经保证了不会出现负数和多余的字符）
//        for (int value : count.values()) {
//            if (value != 0) {
//                return false;
//            }
//        }

        return true;  // 如果所有计数都为0，说明是字母异位词
    }

    // 排序法
    public boolean isAnagramBySort(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        // 将字符串转换为字符数组
        char[] charS = s.toCharArray();
        char[] charT = t.toCharArray();

        // 排序字符数组
        Arrays.sort(charS);
        Arrays.sort(charT);

        // 将排序后的字符数组转换回字符串后比较两个排序后的字符串是否相等
        return Arrays.toString(charS).equals(Arrays.toString(charT));
    }
}
