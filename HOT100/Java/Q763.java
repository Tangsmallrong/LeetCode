package hot100;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * 划分字母区间
 * 贪心算法
 */
public class Q763 {
    public List<Integer> partitionLabels(String s) {
        // 定义数组用于存储字符串中每个字符在字符串里出现的最远位置
        int[] hash = new int[27];

        // 遍历字符串, 计算每个字符出现的最远位置
        for (int i = 0; i < s.length(); i++) {
            hash[s.charAt(i) - 'a'] = i;
        }

        // 定义结果数组
        List<Integer> res = new ArrayList<>();
        // 定义区间的左右边界
        int left = 0;
        int right = 0;

        // 遍历字符串
        for (int i = 0; i < s.length(); i++) {
            // 更新右边界为当前遍历字符中出现的最远位置中最大值
            right = Math.max(right, hash[s.charAt(i) - 'a']);

            // 判断当前是否遍历到右边界(说明前边的所有字符只出现在该区间中)
            if (i == right) {
                // 收集结果
                res.add(right - left + 1);

                // 更新左边界
                left = i + 1;
            }
        }

        return res;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String s = input.nextLine();

        Q763 solution = new Q763();
        List<Integer> res = solution.partitionLabels(s);

        for (Integer num : res) {
            System.out.println(num);
        }
    }
}
