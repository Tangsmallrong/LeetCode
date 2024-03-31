package array;

import java.util.Scanner;

/**
 * 满足总和大于所给值的长度最小的子数组
 * 双指针滑动窗口
 *
 * @author thr
 */
public class Q209 {
    public int minSubArrayLen(int target, int[] nums) {
        int result = Integer.MAX_VALUE;
        int i = 0, sum = 0;

        for (int j = 0; j < nums.length; j++) {
            sum += nums[j];

            while (sum >= target) {
                int len = j - i + 1;
                result = Math.min(result, len);
                sum -= nums[i++];
            }
        }

        return result == Integer.MAX_VALUE ? 0 : result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int target;

        // 输入目标值
        System.out.print("请输入目标值: ");
        target = scanner.nextInt();
        scanner.nextLine(); // 忽略掉之前读取整数后留下的换行符

        // 输入数组
        System.out.print("请输入数组（以空格分隔，回车结束）: ");
        String line = scanner.nextLine();
        String[] numsStr = line.split(" ");
        int[] nums = new int[numsStr.length];
        for (int i = 0; i < numsStr.length; i++) {
            nums[i] = Integer.parseInt(numsStr[i]);
        }

        Q209 solution = new Q209();
        int result = solution.minSubArrayLen(target, nums);

        // 输出最短子数组的长度
        System.out.println("最短子数组的长度: " + result);

        scanner.close();
    }
}
