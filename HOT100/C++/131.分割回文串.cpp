/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
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
    vector<string> path;
    vector<vector<string>> res;

    vector<vector<string>> partition(string s) {
        if (s.size() == 0) return res;
        
        backTracking(s, 0);
        return res;
    }

    void backTracking(string s, int startIndex) {
        // 递归终止条件
        if (startIndex >= s.size()) {
            res.push_back(path);
            return;
        }

        // 单层递归逻辑
        for (int i = startIndex; i < s.size(); i++) {
            // 判断子串是否回文
            if (!isPalindrome(s, startIndex, i)) {
                continue;
            }

            path.push_back(s.substr(startIndex, i - startIndex + 1));

            // 递归
            backTracking(s, i + 1);

            // 回溯
            path.pop_back();
        }
    }

    bool isPalindrome(string s, int start, int end) {
        int i = start;
        int j = end;

        for (; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

int main() {
    // 读取输入
    string s;
    getline(cin, s);

    Solution solution;
    vector<vector<string>> result = solution.partition(s);

    for (vector<string> res : result) {
        for (string str : res) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
