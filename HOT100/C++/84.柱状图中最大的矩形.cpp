/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

#include <string.h>
#include <stack>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 定义栈和面积总和最值
        stack<int> stk;
        int res = 0;

        // 数组首尾插入0
        heights.insert(heights.begin(), 0);
        heights.push_back(0);

        // 遍历数组
        stk.push(0);
        for (int i = 1; i < heights.size(); i++) {
            if (heights[i] >= heights[stk.top()]) {
                stk.push(i);
            } else {
                while (!stk.empty() && heights[i] < heights[stk.top()]) {
                    // 先记录当前基准柱子高度值所对应下标并出栈
                    int mid = stk.top();
                    stk.pop();
                    
                    // 在栈不空的情况下
                    if (!stk.empty()) {
                        // 计算当前组成的矩形面积
                        int h = heights[mid];
                        int w = i - stk.top() - 1;
                        res = max(h * w, res);
                    }
                }
                stk.push(i);
            }
        }

        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> heights;
    int n, height;

    cout << "请输入柱子的数量: ";
    cin >> n;

    cout << "请输入每个柱子的高度: ";
    for (int i = 0; i < n; ++i) {
        cin >> height;
        heights.push_back(height);
    }

    int result = solution.largestRectangleArea(heights);
    cout << "最大的矩形面积是: " << result << endl;

    return 0;
}