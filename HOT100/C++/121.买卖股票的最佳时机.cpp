/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
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
    int maxProfit(vector<int>& prices) {
        int cost = INT_MAX;
        int profit = 0;

        for (int price : prices) {
            cost = min(cost, price);
            profit = max(price - cost, profit);
        }

        return profit;
    }
};
// @lc code=end

int main() {
    // 读取输入
    string line;
    getline(cin, line);
    istringstream ss1(line);
    vector<int> prices;
    int num;
    while (ss1 >> num) {
        prices.push_back(num);
    }

    Solution solution;
    int result = solution.maxProfit(prices);
    cout << result << endl;
}