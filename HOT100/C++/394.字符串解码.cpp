/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

#include <string.h>
#include <stack>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // 辅助栈法
    string decodeString(string s) {
        int multi = 0;  // 存储字符串需要重复的次数
        string res = "";  // 存储中间字符串
        stack<pair<int, string>> stk;  // 用于存储重复次数和当前结果

        // 遍历字符串
        for (char c : s) {
            if (isdigit(c)) {
                // 遇到数字字符, 更新 multi 的值
                multi = multi * 10 + (c - '0');
            } else if (c == '[') {
                // 遇到左方括号, 将当前 multi 和 res 入栈, 并重置 multi 和 res
                stk.push({multi, res});
                multi = 0;
                res = "";
            } else if (c == ']') {
                // 遇到右方括号, 将栈顶元素出栈, 进行字符串拼接
                int num = stk.top().first;
                string str = stk.top().second;
                stk.pop();
                for(int i = 0; i < num; i++) {
                    str += res;
                }
                res = str;  // 更新当前结果字符串
            } else {
                // 遇到普通字符, 直接拼接到当前结果字符串中
                res += c;
            }
        }

        return res;  // 返回最终解码后的字符串
    }
};
// @lc code=end

int main() {
    Solution solution;
    string s;
    cout << "请输入编码字符串: ";
    cin >> s;
    string result = solution.decodeString(s);
    cout << "解码后的字符串: " << result << endl;
    return 0;
}