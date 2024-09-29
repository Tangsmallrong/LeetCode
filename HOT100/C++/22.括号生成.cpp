/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start

#include <string.h>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string str;
    vector<string> res;

    vector<string> generateParenthesis(int n) {
        if (n == 0) return res;

        str.resize(2 * n);
        backTracking(0, 0, 0, n);
        return res;
    }

    void backTracking(int i, int left, int right, int n) {
        // 递归终止条件
        if (left == n && right == n) {
            res.push_back(str);
            return;
        }

        // 单层递归逻辑
        if (left < n) {
            str[i] = '(';
            backTracking(i + 1, left + 1, right, n);
        }

        if (right < left) {
            str[i] = ')';
            backTracking(i + 1, left, right + 1, n);
        }
    }
};
// @lc code=end

int main() {
    int n;
    cin >> n;

    Solution solution;
    vector<string> result = solution.generateParenthesis(n);
    
    for (string str : result) {
        cout << str << endl;
    }
}