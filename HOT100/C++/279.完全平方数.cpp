/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
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
    int numSquares(int n) {
        // 定义 dp 数组
        vector<int> dp(n + 1, INT_MAX);

        // 初始化
        dp[0] = 0;

        // 遍历
        for (int i = 1; i * i <= n; i++) {
            for (int j = i * i; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }

        return dp[n];
    }
};
// @lc code=end

int main() {
    int n;
    cin >> n;

    Solution solution;
    int res = solution.numSquares(n);
    cout << res << endl;
}