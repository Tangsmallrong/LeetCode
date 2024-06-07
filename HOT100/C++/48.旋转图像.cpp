/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

#include <string.h>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 获取矩阵长宽
        int n = matrix.size();

        // 用翻转代替旋转
        // 原转换公式: matrix[i]][j] = matrix[j][n - i - 1]
        // 先分两步走, 先沿左对角线对称
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 再沿垂直轴翻转
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};
// @lc code=end

int main() {
    int n;
    cout << "请输入矩阵的大小 n: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "请输入矩阵元素，每行一个: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // 创建 Solution 对象并调用 rotate 方法
    Solution solution;
    solution.rotate(matrix);

    // 输出结果
    cout << "顺时针旋转 90 度后的矩阵为: " << endl;
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}