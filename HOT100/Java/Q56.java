package hot100;

import java.util.*;

/**
 * 合并区间
 */
public class Q56 {
    public int[][] merge(int[][] intervals) {
        // 如果集合本身为空则直接返回
        if (intervals.length == 0) return intervals;

        // 定义结果集合
        List<int[]> resList = new ArrayList<>();

        // 对原集合里的区间进行排序, 按照每个区间的左边界大小排序
        // lambda 表达式: (a, b) -> Integer.compare(a[0], b[0])
        // 也可以使用 Comparator.comparingInt 方法提取键进行比较
        Arrays.sort(intervals, Comparator.comparingInt((int[] a) -> a[0]));

        // 先将第一个区间存入结果集合中
        resList.add(intervals[0]);
        // 遍历原集合里的区间进行重叠判断或合并操作
        for (int[] interval : intervals) {
            // 获取结果集合中最后一个区间
            int[] last = resList.get(resList.size() - 1);

            // 判断是否重叠
            if (interval[0] <= last[1]) {
                // 合并区间
                last[1] = Math.max(last[1], interval[1]);
            } else {  // 不重叠
                resList.add(interval);
            }
        }

        // 将List转换为int[][]
        return resList.toArray(new int[resList.size()][]);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入区间的数量
        System.out.println("请输入区间的数量: ");
        int n = scanner.nextInt();

        // 初始化区间数组
        int[][] intervals = new int[n][2];
        System.out.println("请输入每个区间的起始和结束位置: ");
        for (int i = 0; i < n; i++) {
            intervals[i][0] = scanner.nextInt();
            intervals[i][1] = scanner.nextInt();
        }

        Q56 q56 = new Q56();
        int[][] result = q56.merge(intervals);

        // 输出结果
        System.out.println("合并后的区间为: ");
        for (int[] interval : result) {
            System.out.println(Arrays.toString(interval));
        }

        // 关闭扫描器
        scanner.close();
    }
}
