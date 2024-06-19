/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
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
        // 先获取矩阵的长宽
        int m = matrix.size();
        int n = matrix[0].size();

        // 定义搜索边界
        int left = 0;
        int right = m * n - 1;

        // 遍历数组 闭区间
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int i = mid / n, j = mid % n;

            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};
// @lc code=end

int main() {
    int m, n, target;
    cout << "请输入矩阵的行数和列数: ";
    cin >> m >> n;
    
    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "请输入矩阵元素: " << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    cout << "请输入目标值: ";
    cin >> target;
    
    Solution solution;
    bool result = solution.searchMatrix(matrix, target);
    if (result) {
        cout << "目标值存在于矩阵中" << endl;
    } else {
        cout << "目标值不存在于矩阵中" << endl;
    }
    
    return 0;
}