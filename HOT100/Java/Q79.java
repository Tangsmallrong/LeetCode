package hot100;

import java.util.Scanner;

/**
 * 单词搜索
 * 回溯
 */
public class Q79 {
    // 方向数组, 便于确定相邻单元格的下标
    int[] dx = {-1, 0, 1, 0};
    int[] dy = {0, -1, 0, 1};

    public boolean exist(char[][] board, String word) {
        // 遍历矩阵中所有单元格, 分别进行递归回溯判断以该单元格为起点是否可以得到目标字符串
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (backTracking(board, word, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }

    private boolean backTracking(char[][] board, String word, int index, int x, int y) {
        // 递归终止条件
        if (board[x][y] != word.charAt(index)) return false;
        if (index == word.length() - 1) return true;

        // 记录当前访问单元格
        char ch = board[x][y];
        // 标记已访问
        board[x][y] = '.';

        // 遍历当前位置的相邻四个单元格
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 判断是否越界或是否已被访问
            if (nx < 0 || nx >= board.length || ny < 0 || ny >= board[0].length || board[nx][ny] == '.') {
                continue;
            }

            // 递归判断相邻单元格
            if (backTracking(board, word, index + 1, nx, ny)) return true;
        }

        // 回溯
        board[x][y] = ch;

        return false;
    }

    /*
        3 4
        ABCD
        EFGH
        IJKL
        ABCG
     */
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int rows = input.nextInt();
        int cols = input.nextInt();
        input.nextLine(); // 消耗换行符
        char[][] board = new char[rows][cols];

        for (int i = 0; i < rows; i++) {
            String line = input.nextLine();
            board[i] = line.toCharArray();  // 将每行字符串转换为字符数组
        }

        String word = input.nextLine();

        Q79 solution = new Q79();
        boolean exist = solution.exist(board, word);
        System.out.println(exist);
    }
}
