package hot100;

import java.util.*;

/**
 * 前k个高频元素
 * 小顶堆
 */
public class Q347 {
    public int[] topKFrequent(int[] nums, int k) {
        // 定义哈希表, 用于存储元素及其出现次数
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            // 如果 num 已经在 map 中, 则其对应的值（出现次数）加 1
            // 否则将其添加到 map 中, 初始值为 1
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        // 定义优先队列实现小顶堆, 用于存储频率最高的 k 个元素
        // 使用 Comparator.comparingInt(Map.Entry::getValue) 来比较元素的出现次数
        PriorityQueue<Map.Entry<Integer, Integer>> minHeap = new PriorityQueue<>(
                // 也可: (a, b) -> a.getValue() - b.getValue()
                Comparator.comparingInt(Map.Entry::getValue)
        );

        // 遍历哈希表, 将每个元素及其出现次数加入优先队列中
        for (Map.Entry<Integer, Integer> next : map.entrySet()) {
            minHeap.offer(next);  // 入队
            // 如果优先队列的大小超过 k, 则移除队列顶部的元素（出现次数最小的元素）
            if (minHeap.size() > k) {
                minHeap.poll();  // 出队
            }
        }

        // 遍历小顶堆, 存储结果到数组中
        int[] res = new int[k];
        for (int i = k - 1; minHeap.peek() != null; i--) {
            // 从优先队列中取出 k 个元素, 存储到结果数组中
            res[i] = minHeap.poll().getKey();
        }

        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入数组元素的个数：");
        int n = scanner.nextInt();
        int[] nums = new int[n];
        System.out.println("请输入数组元素：");
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println("请输入 k 值：");
        int k = scanner.nextInt();

        Q347 solution = new Q347();
        int[] result = solution.topKFrequent(nums, k);
        System.out.println("出现频率前 " + k + " 高的元素为：");
        for (int num : result) {
            System.out.print(num + " ");
        }
    }
}
