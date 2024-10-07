/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
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
    int maxSubArray(vector<int>& nums) {
        // 定义dp数组并初始化
        vector<int> dp(nums.size());
        dp[0] = nums[0]; 

        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }

        return res;
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
    int result = solution.maxSubArray(nums);
    cout << result << endl;
}

