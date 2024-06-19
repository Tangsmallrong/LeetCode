package hot100;

import java.util.Scanner;

/**
 * 搜索二维矩阵
 */
public class Q74 {
    // 开区间写法
    public boolean searchMatrix(int[][] matrix, int target) {
        // 先获取矩阵的大小
        int m = matrix.length;
        int n = matrix[0].length;

        // 定义左右指针
        int left = -1;
        int right = m * n;

        // 遍历矩阵, 将二维矩阵映射为一维数组
        // 映射规律 [i][j] ==> i = x / n, j = x % n
        while (left + 1 < right) {
            int mid = left + (right  - left) / 2;
            int i = mid / n;
            int j = mid % n;

            if (matrix[i][j] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }

        // 检查是否越界
        return right < m * n && matrix[right / n][right % n] == target;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入矩阵的行数和列数
        System.out.println("请输入矩阵的行数和列数: ");
        int m = scanner.nextInt();
        int n = scanner.nextInt();

        // 初始化矩阵
        int[][] matrix = new int[m][n];
        System.out.println("请输入矩阵元素: ");
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = scanner.nextInt();
            }
        }

        // 输入目标值
        System.out.println("请输入目标值: ");
        int target = scanner.nextInt();

        Q74 q74 = new Q74();
        boolean result = q74.searchMatrix(matrix, target);

        // 输出结果
        if (result) {
            System.out.println("目标值存在于矩阵中");
        } else {
            System.out.println("目标值不存在于矩阵中");
        }

        scanner.close();
    }
}
