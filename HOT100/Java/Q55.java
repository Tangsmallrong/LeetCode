package hot100;

import java.util.Scanner;

/**
 * 跳跃游戏
 * 贪心算法
 */
public class Q55 {
    public boolean canJump(int[] nums) {
        int cover = 0;

        if (nums.length == 1) return true;

        // 遍历覆盖范围
        for (int i = 0; i <= cover; i++) {
            cover = Math.max(cover, i + nums[i]);

            // 若当前的覆盖范围大于数组的尾元素下标, 说明可以到达, 直接返回true
            if (cover >= nums.length - 1) {
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        String[] split = str.split("\\s+");
        int[] nums = new int[split.length];

        for (int i = 0; i < nums.length; i++) {
            nums[i] = Integer.parseInt(split[i]);
        }

        Q55 solution = new Q55();
        boolean res = solution.canJump(nums);
        System.out.println(res);
    }
}
