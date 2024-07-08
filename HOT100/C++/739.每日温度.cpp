/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk; 
        vector<int> res(temperatures.size(), 0);  // 结果数组

        // 先将第一个元素 push 入栈
        stk.push(0);
        // 遍历数组元素
        for (int i = 1; i < temperatures.size(); i++) {
            // 若当前元素小于等于栈顶元素, 则直接入栈(注意入的是下标)
            if (temperatures[i] <= temperatures[stk.top()]) {
                stk.push(i);              
            } else {  
                // 若栈不空且当前元素大于栈顶元素
                while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                    // 计算下标差并存入结果数组
                    res[stk.top()] = i - stk.top();

                    // 将栈顶元素弹出
                    stk.pop();
                }
                // 将当前元素入栈
                stk.push(i);
            }
        }

        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    int n;
    cout << "请输入温度数组的长度: ";
    cin >> n;

    vector<int> temperatures(n);
    cout << "请输入温度数组: ";
    for (int i = 0; i < n; i++) {
        cin >> temperatures[i];
    }

    vector<int> result = solution.dailyTemperatures(temperatures);

    cout << "下一个更高温度出现的天数: ";
    for (int r : result) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}