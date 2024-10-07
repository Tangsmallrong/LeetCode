/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
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
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        // dp 数组
        vector<int> dp(nums.size());

        // 初始化
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // 遍历
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[nums.size() - 1];
    }
};
// @lc code=end

int main() {
    // 读取输入
    string line;
    getline(cin, line);
    istringstream ss1(line);
    vector<int> nums;
    int num;
    while (ss1 >> num) {
        nums.push_back(num);
    }

    Solution solution;
    int result = solution.rob(nums);
    cout << result << endl;
}