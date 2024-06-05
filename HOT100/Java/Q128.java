package hot100;

import java.util.HashSet;
import java.util.Scanner;

/**
 * 最长连续序列
 */
public class Q128 {
    public int longestConsecutive(int[] nums) {
        // 将数组存储在 Set 集合中(去重+方便查找)
        HashSet<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }

        int len = 0;
        // 遍历 Set 集合
        for (Integer num : set) {
            // 查找序列起点
            if (!set.contains(num - 1)) {  // 如果 num 是序列起点
                // 计算序列长度
                int next = num + 1;

                while (set.contains(next)) {
                    next++;
                }

                len = Math.max(len, next - num);
            }
        }

        return len;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入整数数组
        System.out.println("请输入整数数组（以空格分隔，回车结束）: ");
        String input = scanner.nextLine();
        String[] inputArray = input.split(" ");
        int[] nums = new int[inputArray.length];
        for (int i = 0; i < inputArray.length; i++) {
            nums[i] = Integer.parseInt(inputArray[i]);
        }

        Q128 solution = new Q128();
        int result = solution.longestConsecutive(nums);

        // 输出结果
        System.out.println("最长连续序列的长度为: " + result);

        scanner.close();
    }
}
