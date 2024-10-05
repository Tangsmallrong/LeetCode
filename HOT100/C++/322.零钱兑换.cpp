/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
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
    int coinChange(vector<int>& coins, int amount) {
        // dp 数组, 初始化非0下标为INT_MAX
        vector<int> dp(amount + 1, INT_MAX);

        dp[0] = 0;

        // 遍历
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (dp[j - coins[i]] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }

        if (dp[amount] == INT_MAX) {
            return -1;
        }

        return dp[amount];
    }
};
// @lc code=end

int main() {
    // 读取输入
    string line;
    getline(cin, line);

    int amount;
    cin >> amount;

    istringstream ss1(line);
    vector<int> coins;
    int num;
    while (ss1 >> num) {
        coins.push_back(num);
    }

    Solution solution;
    int result = solution.coinChange(coins, amount);
    cout << result << endl;
}