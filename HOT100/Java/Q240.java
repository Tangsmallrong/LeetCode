package hot100;

import java.util.Scanner;

/**
 * 搜索二维矩阵 II
 */
public class Q240 {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }

        int m = 0;
        int n = matrix[0].length - 1;

        while (m < matrix.length && n >= 0) {
            if (matrix[m][n] == target) {
                return true;
            } else if (matrix[m][n] > target) {
                n--;
            } else {
                m++;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入矩阵的行数和列数
        System.out.println("请输入矩阵的行数和列数: ");
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();

        // 初始化矩阵
        int[][] matrix = new int[rows][cols];
        System.out.println("请输入矩阵元素，每行一个: ");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }

        // 输入目标值
        System.out.println("请输入目标值: ");
        int target = scanner.nextInt();

        Q240 solution = new Q240();
        boolean result = solution.searchMatrix(matrix, target);

        // 输出结果
        System.out.println("目标值 " + (result ? "存在" : "不存在") + " 于矩阵中");

        scanner.close();
    }
}
