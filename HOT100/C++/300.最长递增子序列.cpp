/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
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
    int lengthOfLIS(vector<int>& nums) {
        // 定义dp数组, 初始化为1
        vector<int> dp(nums.size(), 1);

        // 记录结果
        int res = 1;
        // 遍历
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

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
    int result = solution.lengthOfLIS(nums);
    cout << result << endl;
}