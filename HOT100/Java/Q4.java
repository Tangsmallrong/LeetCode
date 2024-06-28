package hot100;

import java.util.Scanner;

/**
 * 寻找两个正序数组的中位数
 */
public class Q4 {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        // 合并两数组后寻找中位数
        int len1 = nums1.length;
        int len2 = nums2.length;
        int len = len1 + len2;
        int[] nums = new int[len];

        int i = 0;
        int j = 0;
        int k = 0;
        while (i < len1 && j < len2) {
            if (nums1[i] < nums2[j]) {
                nums[k++] = nums1[i++];
            } else {
                nums[k++] = nums2[j++];
            }
        }

        // 剩下的元素
        while (i < len1) nums[k++] = nums1[i++];
        while (j < len2) nums[k++] = nums2[j++];

        // 计算中位数
        if (len % 2 == 0) {
            return (nums[(len - 1) / 2] + nums[len / 2]) / 2.0;
        } else {
            return nums[len / 2];
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入第一个数组
        System.out.println("请输入第一个数组的长度: ");
        int n1 = scanner.nextInt();
        int[] nums1 = new int[n1];
        System.out.println("请输入第一个数组的元素: ");
        for (int i = 0; i < n1; i++) {
            nums1[i] = scanner.nextInt();
        }

        // 输入第二个数组
        System.out.println("请输入第二个数组的长度: ");
        int n2 = scanner.nextInt();
        int[] nums2 = new int[n2];
        System.out.println("请输入第二个数组的元素: ");
        for (int i = 0; i < n2; i++) {
            nums2[i] = scanner.nextInt();
        }

        // 计算并输出中位数
        Q4 q4 = new Q4();
        double median = q4.findMedianSortedArrays(nums1, nums2);
        System.out.println("两个正序数组的中位数是: " + median);

        scanner.close();
    }

    // 递归解法
    public double findMedianSorted(int[] nums1, int[] nums2) {
        // 获取两数组总长度, 用于判断奇偶
        int len = nums1.length + nums2.length;

        if (len % 2 == 0) {  // 偶数
            int left = find(nums1, 0, nums2, 0, len / 2);
            int right = find(nums1, 0, nums2, 0, len / 2 + 1);
            return (left + right) / 2.0;
        } else {  // 奇数
            return find(nums1, 0, nums2, 0, len / 2 + 1);
        }
    }

    public int find(int[] nums1, int start1, int[] nums2, int start2, int k) {
        // 保证 nums1 不长于 nums2
        if (nums1.length - start1 > nums2.length - start2) {
            return find(nums2, start2, nums1, start1, k);
        }

        // 处理特殊情况
        // 当 nums1 剩余长度为 0 时, 返回 nums2 的第 k 大的数
        if (nums1.length == start1) {
            return nums2[start2 + k - 1];
        }
        // 当 k 为 1 时, 返回 num1 和 nums2 中较小的那个
        if (k == 1) {
            return Math.min(nums1[start1], nums2[start2]);
        }

        // 二分查找, 每次递归排除掉一部分元素
        // 将 k 分成两部分, 一部分在 nums1 中, 另一部分在 nums2 中
        int idx1 = start1 + Math.min(nums1.length, k / 2);  // k / 2 用于将 k 分成两部分
        int idx2 = start2 + k - k / 2;  // k - k / 2 确保即使 k 为奇数, 两部分之和仍然等于 k

        // 每次比较两个数组中第 k / 2 个元素, 较小的那一部分不可能包含第 k 小的元素, 因此可以排除掉
        if (nums1[idx1 - 1] < nums2[idx2 - 1]) {
            return find(nums1, idx1, nums2, start2, k - (idx1 - start1));
        } else {
            return find(nums1, start1, nums2, idx2, k - (idx2 - start2));
        }
    }
}



