package hot100;

import java.util.Scanner;

/**
 * 矩阵置零
 */
public class Q73 {
    public void setZeroes(int[][] matrix) {
        // 获取数组的行列
        int m = matrix.length; // 行
        int n = matrix[0].length;  // 列

        // 标记第一行和第一列是否存在为0的元素
        boolean rowZero = false;
        boolean colZero = false;

        // 遍历数组
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;

                    if (i == 0) rowZero = true;
                    if (j == 0) colZero = true;
                }
            }
        }

        // 根据第一行和第一列为0的位置给数组置零
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // 最后判断第一行和第一列是否要赋值为零
        if (rowZero) {
            for (int i = 0; i < n; i++) matrix[0][i] = 0;
        }
        if (colZero) {
            for (int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入矩阵的行数和列数
        System.out.println("请输入矩阵的行数和列数: ");
        int m = scanner.nextInt();
        int n = scanner.nextInt();

        // 初始化矩阵
        int[][] matrix = new int[m][n];

        // 输入矩阵元素
        System.out.println("请输入矩阵元素，以空格分隔: ");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }

        Q73 solution = new Q73();
        solution.setZeroes(matrix);

        // 输出结果
        System.out.println("处理后的矩阵为: ");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }

        scanner.close();
    }
}
