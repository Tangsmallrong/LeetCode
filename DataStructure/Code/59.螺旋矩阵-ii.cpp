/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include <string.h>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int startX = 0, startY = 0;  // 起始位置
        int offset = 1;  // 控制缩小范围
        int count = 1;  // 填充的数字
        // 初始化二维 vector 分配空间 n*n
        vector<vector<int>> nums(n, vector<int>(n));

        while (offset <= (n / 2)) {  // n^2 个数, 需至少循环 n / 2 圈
            // 4 个循环, 遍历 4 条边
            // 顺时针: 上右下左
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
            for ( ; j > startY; j--) {
                nums[i][j] = count++;
            }

            // 左
            for ( ; i > startX; i--) {
                nums[i][j] = count++;
            }

            // 起始位置++, 偏移量++
            startX++;
            startY++;
            offset++;
        }

        // 如果 n 为奇数, 则还需要对中间元素单独赋值
        if (n % 2 == 1) {
            nums[startX][startY] = count++;
        }

        return nums;
    }
};
// @lc code=end


int main() {
    int n;
    cout << "请输入正方形矩阵的大小 n: ";
    cin >> n;

    Solution solution;
    vector<vector<int>> matrix = solution.generateMatrix(n);

    // 打印生成的矩阵
    cout << "生成的螺旋矩阵如下：" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
