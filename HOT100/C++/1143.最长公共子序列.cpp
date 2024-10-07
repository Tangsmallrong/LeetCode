/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
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
    int longestCommonSubsequence(string text1, string text2) {
        // 定义dp数组, 默认初始化均为0
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        // 遍历两个字符串
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[text1.size()][text2.size()];
    }
};
// @lc code=end

int main() {
    // 读取输入
    string text1;
    string text2;
    getline(cin, text1);
    getline(cin, text2);

    Solution solution;
    int result = solution.longestCommonSubsequence(text1, text2);
    cout << result << endl;
}

