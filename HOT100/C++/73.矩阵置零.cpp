/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
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
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();  // 长
        int n = matrix[0].size();  // 宽

        // 用于记录数组第一行第一列原本是否存在为0的元素
        bool rowZero = false, colZero = false;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    // 用数组的第一行和第一列标记数组中其他位置为0的元素下标
                    matrix[0][j] = 0;
                    matrix[i][0]= 0;

                    if (i == 0) rowZero = true;
                    if (j == 0) colZero = true;
                }
            }
        }

        // 根据第一行和第一列的为0的位置对其他行列需要为0的位置进行赋值
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                } 
            }
        }

        // 根据第一行和第一列原本是否存在0元素的标志对第一行和第一列进行赋值
        if (rowZero) {
            for (int i = 0; i < n; i++) matrix[0][i] = 0;
        }

        if (colZero) {
            for (int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    }
};
// @lc code=end

int main() {
    int m, n;
    cout << "请输入矩阵的行数和列数: ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "请输入矩阵元素，每行一个: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // 创建 Solution 对象并调用 setZeroes 方法
    Solution solution;
    solution.setZeroes(matrix);

    // 输出结果
    cout << "处理后的矩阵为: " << endl;
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}