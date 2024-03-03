/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

#include <string.h>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};

        // 计算行和列
        int rows = matrix.size();
        int cols = matrix[0].size();

        int startX = 0, startY = 0;  // 起始行和列
        int offset = 1;  // 每次循环减少的行列数
        int loop = min(rows, cols) / 2; // 需要循环的次数
        int count = 0; // 输出数组的当前索引
        vector<int> nums(rows * cols);  // 结果数组

        while (loop--) {
            int i, j;

            // 上
            for (j = startY; j < cols - offset; j++) {
                nums[count++] = matrix[startX][j];
            }

            // 右
            for (i = startX; i < rows - offset; i++) {
                nums[count++] = matrix[i][j];
            }

            // 下
            for ( ; j > startY; j--) {
                nums[count++] = matrix[i][j];
            }

            // 左
            for ( ; i > startX; i--) {
                nums[count++] = matrix[i][j];
            }

            startX++;
            startY++;
            offset++;
        }

        
        // 如果行或列的较小值为奇数, 矩阵的行数或列数中至少有一个是奇数
        // 在螺旋遍历结束后，可能会剩下一行或一列没有被遍历
        if (min(rows, cols) % 2 != 0) {

            // 行小于列 ==> 剩下一行 上
            if (rows <= cols) {
                for (int j = startY; j < cols - offset + 1; j++) {
                    nums[count++] = matrix[startX][j];
                } 
            } else {  // 行大于列 ==> 剩下一列 右
                for (int i = startX; i < rows - offset + 1; i++) {
                    nums[count++] = matrix[i][startY];
                }
            }
        }

        return nums;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> matrix;
    int m, n;
    cout << "请输入行数: ";
    cin >> m;
    cout << "请输入列数: ";
    cin >> n;

    cout << "逐行输入矩阵元素:" << endl;
    for (int i = 0; i < m; ++i) {
        vector<int> row(n);
        for (int j = 0; j < n; ++j) {
            cin >> row[j]; // 输入每一行的元素
        }
        matrix.push_back(row); // 将行添加到矩阵中
    }

    Solution solution;
    vector<int> result = solution.spiralOrder(matrix);

    cout << "螺旋顺序: ";
    for (int num : result) {
        cout << num << " "; // 输出螺旋顺序的元素
    }
    cout << endl;

    return 0;
}

// 参考解法-更优雅易懂
// vector<int> spiralOrder(vector<vector<int>>& matrix) {
//     vector <int> ans;
//     if(matrix.empty()) return ans; //若数组为空，直接返回答案
//     int u = 0; //赋值上下左右边界
//     int d = matrix.size() - 1;
//     int l = 0;
//     int r = matrix[0].size() - 1;
//     while(true)
//     {
//         for(int i = l; i <= r; ++i) ans.push_back(matrix[u][i]); //向右移动直到最右
//         if(++ u > d) break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
//         for(int i = u; i <= d; ++i) ans.push_back(matrix[i][r]); //向下
//         if(-- r < l) break; //重新设定有边界
//         for(int i = r; i >= l; --i) ans.push_back(matrix[d][i]); //向左
//         if(-- d < u) break; //重新设定下边界
//         for(int i = d; i >= u; --i) ans.push_back(matrix[i][l]); //向上
//         if(++ l > r) break; //重新设定左边界
//     }
//     return ans;
// }
