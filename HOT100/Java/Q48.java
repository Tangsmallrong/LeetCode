package hot100;

import java.util.Scanner;

/**
 * 旋转图像
 */
public class Q48 {
    public void rotate(int[][] matrix) {
        // 先获取矩阵的大小
        int n = matrix.length;

        // 利用翻转代替旋转, 遍历矩阵, 原地进行交换赋值
        // 先关于左对角线翻转对称
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // 在关于中轴垂直翻转
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = temp;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入矩阵的大小
        System.out.println("请输入矩阵的大小 n: ");
        int n = scanner.nextInt();

        // 初始化矩阵
        int[][] matrix = new int[n][n];
        System.out.println("请输入矩阵元素，每行一个: ");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }

        Q48 solution = new Q48();
        solution.rotate(matrix);

        // 输出结果
        System.out.println("顺时针旋转 90 度后的矩阵为: ");
        for (int[] row : matrix) {
            for (int elem : row) {
                System.out.print(elem + " ");
            }
            System.out.println();
        }

        // 关闭扫描器
        scanner.close();
    }
}
