/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
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
    int trap(vector<int>& height) {
        stack<int> stk;  // 定义栈，用于存储柱子的下标
        int sum = 0;  // 记录可存储的雨水面积

        // 遍历数组, 注意先入栈第一个元素(栈中存储元素下标)
        stk.push(0);
        for (int i = 1; i < height.size(); i++) {
            if (height[i] <= height[stk.top()]) {
                // 当前柱子高度小于等于栈顶柱子高度，将当前柱子下标入栈
                stk.push(i);
            } else {
                // 当前柱子高度大于栈顶柱子高度，说明可以接雨水
                while (!stk.empty() && height[i] > height[stk.top()]) {
                    // 获取凹槽中间元素的下标, 注意获取后弹出, 方便后续获取凹槽左边值
                    int mid = stk.top(); 
                    stk.pop();

                    // 出栈后注意再次判断栈是否为空！！！防止越界
                    if (!stk.empty()) {
                        // 计算高度和宽度
                        int h = min(height[stk.top()], height[i]) - height[mid];
                        int w = i - stk.top() - 1;
                        // 累加面积
                        sum += h * w;
                    }
                }
                // 将当前柱子下标入栈
                stk.push(i);
            }
        }
        return sum;
    }
};
// @lc code=end

int main() {
    Solution solution;
    int n;
    cout << "请输入数组的长度: ";
    cin >> n;
    vector<int> height(n);
    cout << "请输入数组的元素: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int result = solution.trap(height);
    cout << "可以接的雨水总量: " << result << endl;

    return 0;
}