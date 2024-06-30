/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
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
    bool isValid(string s) {
        stack<char> st;

        // 剪枝, 如果字符串长度为奇数, 直接返回 false
        if (s.size() % 2 != 0) {
            return false;
        }

        for (char c : s) {
            // 遇到左括号时入栈(入右括号, 方便匹配)
            if (c == '(') {
                st.push(')');
            } else if (c == '{') {
                st.push('}');
            } else if (c == '[') {
                st.push(']');
            } else if (!st.empty() && st.top() == c) {
                // 遇到右括号, 若栈不为空且栈顶与该括号匹配, 弹出栈顶
                st.pop();
            } else {  // 此处包括栈空/栈顶与当前括号不匹配的情况
                return false;
            }
        }

        // 最后检查栈是否为空, 若为空则表示括号全部匹配, 返回 true
        return st.empty();
    }
};
// @lc code=end

int main() {
    string s;
    cout << "请输入字符串: ";
    cin >> s;

    Solution solution;
    bool result = solution.isValid(s);

    cout << "输入字符串是否有效: " << (result ? "true" : "false") << endl;

    return 0;
}


// 减少if-else的优雅版本
// bool isValid(string s) {
//     stack<char> st;
//     unordered_map<char, char> map = 
//         {{')', '('}, {'}', '{'}, {']', '['}};

//     // 剪枝，如果字符串长度为奇数，直接返回 false
//     if (s.size() % 2 != 0) {
//         return false;
//     }

//     for (char c : s) {
//         // 如果是右括号
//         if (map.count(c)) {
//             // 检查栈顶是否与之匹配
//             if (!st.empty() && st.top() == map[c]) {
//                 st.pop();
//             } else {
//                 return false;
//             }
//         } else {
//             // 如果是左括号，压入栈
//             st.push(c);
//         }
//     }

//     return st.empty();
// }