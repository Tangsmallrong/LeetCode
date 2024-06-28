package hot100;

import java.util.HashMap;
import java.util.Scanner;

public class Q560 {
    public int subarraySum(int[] nums, int k) {
        // 哈希表存储前缀和
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);
        int preSum = 0;
        int count = 0;

        // 遍历数组
        for (int num : nums) {
            preSum += num;

            if (map.containsKey(preSum - k)) {
                count += map.get(preSum - k);
            }

            map.put(preSum, map.getOrDefault(preSum, 0) + 1);
        }

        return count;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入数组长度
        System.out.print("请输入数组的长度: ");
        int n = scanner.nextInt();

        // 输入数组元素
        System.out.print("请输入数组元素: ");
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }

        // 输入目标和 k
        System.out.print("请输入目标和 k: ");
        int k = scanner.nextInt();

        Q560 solution = new Q560();
        int result = solution.subarraySum(nums, k);

        // 输出结果
        System.out.println("和为 " + k + " 的子数组个数是: " + result);

        scanner.close();
    }
}
