package hot100;

import java.util.Scanner;

/**
 * 跳跃游戏II
 * 贪心算法
 */
public class Q45 {
    public int jump(int[] nums) {
        if (nums.length == 1) return 0;

        // 定义当前能够跳到的最远位置, 初始设为0
        int maxPos = 0;

        // 定义上次跳跃可到达的右边界, 初始设为0
        int end = 0;

        // 记录跳跃次数
        int res = 0;

        // 遍历数组, 题中说一定能到达末尾, 这里为统一处理遍历到末尾倒二元素即可
        for (int i = 0; i < nums.length - 1; i++) {
            // 更新当前能跳到的最远位置
            maxPos = Math.max(maxPos, i + nums[i]);

            // 判断当前遍历元素是否已经到达上次跳跃的右边界
            if (i == end) {
                // 是则进行下一次的跳跃
                res++;

                // 更新右边界为之前计算的能跳的最远位置
                end = maxPos;
            }
        }

        // 如果遍历数组所有元素, 则还需额外判断是否能跳跃的最远位置已经覆盖了末尾位置以免多次res++
        // 还需在代码开始前特殊处理数组元素只有1个的情况
//        for (int i = 0; i < nums.length; i++) {
//            // 更新当前能跳到的最远位置
//            maxPos = Math.max(maxPos, i + nums[i]);
//
//            // 判断当前遍历元素是否已经到达上次跳跃的右边界
//            if (i == end) {
//                // 是则进行下一次的跳跃
//                res++;
//
//                // 更新右边界为之前计算的能跳的最远位置
//                end = maxPos;
//
//                // 若更新后的右边界已经覆盖末尾位置则直接break
//                if (end == nums.length - 1) break;
//            }
//        }

        return res;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        String[] split = str.split("\\s+");
        int[] nums = new int[split.length];

        for (int i = 0; i < nums.length; i++) {
            nums[i] = Integer.parseInt(split[i]);
        }

        Q45 solution = new Q45();
        int res = solution.jump(nums);
        System.out.println(res);
    }
}
