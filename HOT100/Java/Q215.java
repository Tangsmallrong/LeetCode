package hot100;

import java.util.Random;
import java.util.Scanner;

/**
 * 数组中的第k个最大元素
 * 选择排序
 */
public class Q215 {

    // 创建一个 Random 对象, 并使用当前时间的毫秒数作为种子来初始化它
    private static final Random random = new Random(System.currentTimeMillis());

    public int findKthLargest(int[] nums, int k) {
        // 获取数组长度和排序后目标值所在的下标
        int n = nums.length;
        int target = n - k;
        // 确定初始查找范围
        int left = 0;
        int right = n - 1;

        // 循环调用分区函数, 获取目标下标对应的元素值
        while (true) {
            int pivotIndex = partition(nums, left, right);
            // 比较当前得到的基准元素下标和目标下标
            if (pivotIndex == target) {
                return nums[pivotIndex];
            } else if (target > pivotIndex) {
                // 缩小查找范围到后半部分
                left = pivotIndex + 1;
            } else {
                // 缩小查找范围到前半部分
                right = pivotIndex - 1;
            }
        }
    }

    // 分区
    private int partition(int[] nums, int left, int right) {
        // 随机选择基准元素, 生成一个在 [left, right] 范围内的随机整数
        // nextInt(bound): 返回一个介于 [0, bound) 之间的随机整数
        // 把生成的随机数加上 left, 得到的结果就是一个介于 [left, right] 之间的随机整数
        int randomIndex = left + random.nextInt(right - left + 1);
        int pivot = nums[randomIndex];
        // 将基准元素先与当前查找范围内的首个元素交换
        swap(nums, left, randomIndex);

        // 定义左右指针, 分别对应小于/大于基准元素的部分
        int small = left + 1;
        int big = right;

        // 循环移动双指针确定基准元素所在下标
        while (true) {
            // 循环移动small指针, 直到其指向元素>=基准元素
            while (small <= big && nums[small] < pivot) {
                small++;
            }

            // 循环移动big指针, 直到其指向元素<=基准元素
            while (small <= big && nums[big] > pivot) {
                big--;
            }

            // 再次判断双指针是否重叠或交叉, 若符合条件则直接退出循环
            if (small >= big) {
                break;
            }

            // 交换双指针指向的元素
            swap(nums, small, big);
            small++;
            big--;
        }

        // 将基准元素放回到其下标所在位置
        swap(nums, left, big);
        return big;  // 返回基准元素下标
    }

    private void swap(int[] nums, int idx1, int idx2) {
        int temp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = temp;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入数组的长度:");
        int n = scanner.nextInt();
        int[] nums = new int[n];
        System.out.println("请输入数组元素:");
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println("请输入 k 值:");
        int k = scanner.nextInt();

        Q215 solution = new Q215();
        int result = solution.findKthLargest(nums, k);
        System.out.println("数组中第 " + k + " 大的元素是: " + result);
    }
}
