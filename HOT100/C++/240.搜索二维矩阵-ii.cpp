/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

#include <string.h>
#include <vector>
#include <unordered_set>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 检查矩阵是否为空或其第一行是否为空, 是则直接返回 false
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        // 从右上角开始遍历矩阵
        int m = 0;
        int n = matrix[0].size() - 1;

        // 以右上角的数字为根, 分别向左/向右(下)进行遍历, 类似二叉搜索树
        while (m < matrix.size() && n >= 0) {
            if (matrix[m][n] == target) {
                return true;
            } else if (matrix[m][n] > target) {
                // 目标数字较小, 往左子树走, 也就是列数--
                n--;
            } else {
                m++;
            }
        }

        return false;
    }
};
// @lc code=end

int main() {
    int rows, cols, target;
    cout << "请输入矩阵的行数和列数: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "请输入矩阵元素，每行一个: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "请输入目标值: ";
    cin >> target;

    // 创建 Solution 对象并调用 searchMatrix 方法
    Solution solution;
    bool result = solution.searchMatrix(matrix, target);

    // 输出结果
    cout << "目标值 " << (result ? "存在" : "不存在") << " 于矩阵中" << endl;

    return 0;
}