/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start

#include <string.h>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n) {
        if (n == 0) return res;

        // 初始化棋盘
        vector<string> chessBoard(n, string(n, '.'));

        // 递归
        backTracking(chessBoard, n, 0);
        return res;
    }

    void backTracking(vector<string>& chessBoard, int n, int row) {
        // 递归终止条件
        if (row == n) {
            res.push_back(chessBoard);
            return;
        }

        // 单层递归逻辑
        // 遍历当前行的每列
        for (int i = 0; i < n; i++) {
            // 若当前位置不能放置皇后, 则跳过
            if (!isVaild(chessBoard, n, row, i)) {
                continue;
            }

            // 放皇后
            chessBoard[row][i] = 'Q';

            // 递归
            backTracking(chessBoard, n, row + 1);

            // 回溯
            chessBoard[row][i] = '.';
        }

        return;
    }

    // 判断当前位置是否可以放置皇后
    bool isVaild(vector<string>& chessBoard, int n, int row, int col) {
        // 列
        for (int i = row - 1; i >= 0; i--) {
            if (chessBoard[i][col] == 'Q') {
                return false;
            }
        }

        // 斜 45度
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessBoard[i][j] == 'Q') {
                return false;
            }
        }

        // 斜 135
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessBoard[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }  
};
// @lc code=end

int main() {
    int num;
    cin >> num;

    Solution solution;
    vector<vector<string>> result = solution.solveNQueens(num);

    for (vector<string> res : result) {
        for (string str : res) {
            cout << str << " ";
        }
        cout << endl;
    }
}

