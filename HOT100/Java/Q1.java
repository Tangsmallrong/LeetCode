package hot100;

import java.util.HashMap;
import java.util.Scanner;

/**
 * 两数之和
 */
public class Q1 {
    public int[] twoSum(int[] nums, int target) {
        // 创建哈希表
        HashMap<Integer, Integer> map = new HashMap<>();

        // 遍历数组
        for (int i = 0; i < nums.length; i++) {
            int num = target - nums[i];

            // 查找哈希表是否存在对应的值
            if (map.containsKey(num)) {
                return new int[]{map.get(num), i};
            }

            // 键为数值, 值为下标
            map.put(nums[i], i);
        }

        return new int[]{};
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入整数数组
        System.out.print("请输入整数数组（以空格分隔，回车结束）: ");
        String input = scanner.nextLine();
        String[] inputArray = input.split(" ");
        int[] nums = new int[inputArray.length];
        for (int i = 0; i < inputArray.length; i++) {
            nums[i] = Integer.parseInt(inputArray[i]);
        }

        // 输入目标值
        System.out.print("请输入目标值: ");
        int target = scanner.nextInt();

        Q1 q1 = new Q1();
        int[] result = q1.twoSum(nums, target);

        // 输出结果
        if (result.length == 2) {
            System.out.println("两个数的索引为: " + result[0] + " 和 " + result[1]);
        } else {
            System.out.println("没有找到满足条件的两个数。");
        }

        scanner.close();
    }
}
