package array;

import java.util.Scanner;

/**
 * 螺旋矩阵 II
 * 模拟和循环不变量
 *
 * @author thr
 */
public class Q59 {
    public int[][] generateMatrix(int n) {
        int[][] nums = new int[n][n];
        int startX = 0, startY = 0;
        int offset = 1, count = 1;

        while (offset <= (n / 2)) {
            int i, j;

            // 上
            for (j = startY; j < n - offset; j++) {
                nums[startX][j] = count++;
            }

            // 右
            for (i = startX; i < n - offset; i++) {
                nums[i][j] = count++;
            }

            // 下
            for (; j > startY; j--) {
                nums[i][j] = count++;
            }

            // 左
            for (; i > startX; i--) {
                nums[i][j] = count++;
            }

            startX++;
            startY++;
            offset++;
        }

        if (n % 2 == 1) {
            nums[startX][startY] = count++;
        }

        return nums;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入正方形矩阵的大小
        System.out.print("请输入正方形矩阵的大小 n: ");
        int n = scanner.nextInt();

        Q59 solution = new Q59();
        int[][] matrix = solution.generateMatrix(n);

        // 打印生成的矩阵
        System.out.println("生成的螺旋矩阵如下：");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(matrix[i][j] + "\t");
            }
            System.out.println();
        }

        scanner.close();
    }
}
