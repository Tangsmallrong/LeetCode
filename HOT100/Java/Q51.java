package hot100;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 * N皇后
 * 回溯
 */
public class Q51 {
    // 三维数组, 数组中存放所有符合条件的棋盘摆放方式
    private final List<List<String>> res = new ArrayList<>();

    // [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
    public List<List<String>> solveNQueens(int n) {
        if (n == 0) return res;

        // 初始化棋盘为全'.'
        List<String> chessBoard = new ArrayList<>(Collections.nCopies(n,
                String.join("", Collections.nCopies(n, "."))));
        backTracking(chessBoard, n, 0);
        return res;
    }

    private void backTracking(List<String> chessBoard, int n, int row) {
        // 递归终止条件
        if (row == n) {
            res.add(new ArrayList<>(chessBoard));
            return;
        }

        // 单层递归逻辑
        // 遍历该层的每列元素
        for (int i = 0; i < n; i++) {
            // 判断当前位置是否合法
            if (!isValid(row, i, chessBoard, n)) {
                continue;
            }

            // 合法, 设置[row][i]位置的元素为"Q"
            StringBuilder sb = new StringBuilder(chessBoard.get(row));
            sb.setCharAt(i, 'Q');
            chessBoard.set(row, sb.toString());

            // 递归
            backTracking(chessBoard, n, row + 1);

            // 回溯, 还原[row][i]元素
            sb = new StringBuilder(chessBoard.get(row));
            sb.setCharAt(i, '.');
            chessBoard.set(row, sb.toString());
        }

        return;
    }

    /**
     * 判断当前位置放置皇后是否合法
     */
    private boolean isValid(int row, int col, List<String> chessBoard, int n) {
        // 列
        for (int i = row - 1; i >= 0; i--) {
            if (chessBoard.get(i).charAt(col) == 'Q') {
                return false;
            }
        }

        // 斜边 45度和135度
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessBoard.get(i).charAt(j) == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessBoard.get(i).charAt(j) == 'Q') {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        Q51 solution = new Q51();
        List<List<String>> result = solution.solveNQueens(n);

        for (List<String> res : result) {
            for (String str : res) {
                System.out.print(str + " ");
            }
            System.out.println();
        }
    }
}
