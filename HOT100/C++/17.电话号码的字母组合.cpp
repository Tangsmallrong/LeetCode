/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

#include <string.h>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    string s;  // 存储单个结果
    vector<string> res;  // 所有组合的结果集

    // 数字和字符串的映射
    string arr[10] = {
        "", "",
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> letterCombinations(string digits) {
        if (digits == "") return res;

        // 利用回溯模拟暴力for循环求组合
        backTracking(digits, 0);
        return res;
    }

    void backTracking(string digits, int index) {
        // 递归终止条件
        if (index == digits.size()) {
            res.push_back(s);
            return;
        }

        // 单层递归逻辑
        // 计算当前遍历到的数字字符
        int digit = digits[index] - '0';
        // 根据映射获取该数字字符所对应的字符串
        string str = arr[digit];

        // 遍历字符串
        for (char c : str) {
            s.push_back(c);

            // 递归
            backTracking(digits, index + 1);

            // 回溯
            s.pop_back();
        }
    }
};
// @lc code=end

int main() {
    // 读取输入
    string digits;
    getline(cin, digits);
   
    Solution solution;
    vector<string> res = solution.letterCombinations(digits);

    for (const string& s : res) {
        cout << s << endl;
    }

    return 0;
}