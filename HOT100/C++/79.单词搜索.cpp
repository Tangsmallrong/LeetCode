/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

#include <string.h>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // 定义四个方向, 方便确定相邻单元格的下标
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    bool exist(vector<vector<char>>& board, string word) {
        // 遍历矩阵中每个单元格进行递归回溯检查以该单元格为起点是否能找到目标字符串
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backTracking(board, word, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool backTracking(vector<vector<char>>& board, string word, int idx, int x, int y) {
        // 递归终止条件
        // 若当前单元格的字母和单词的对应位置不匹配则直接返回 false
        if (board[x][y] != word[idx]) return false;
        // 若匹配并且当前下标已经是单词的最后一个位置则返回 true
        if (idx == word.length() - 1) return true;

        // 匹配但还没到单词的最后位置
        // 记录当前单元格的字母(因为后续要用原数组记录访问状态)
        char ch = board[x][y];
        board[x][y] = '.';
        
        // 遍历与当前单元格相邻的四个单元格位置
        for (int i = 0; i < 4; i++) {
            // 分别计算 上左下右 相邻的单元格下标
            int nx = x + dx[i];  
            int ny = y + dy[i]; 

            // 判断是否越界或者是否已经访问过, 是就跳过
            if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || board[nx][ny] == '.') {
                continue;
            }

            // 递归访问相邻的单元格, 若返回 true 说明找到, 直接返回
            if (backTracking(board, word, idx + 1, nx, ny)) return true;
        }

        // 回溯
        board[x][y] = ch;

        // 周围的格子都尝试结束, 直接返回 false
        return false;
    }
};
// @lc code=end

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> board(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    string word;
    cin >> word;

    Solution solution;
    bool result = solution.exist(board, word);
    cout << (result ? "true" : "false") << endl;

    return 0;
}

