/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
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
    bool canPartition(vector<int>& nums) {
        // 计算数组元素总和
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        // 判断数组元素总和是否为奇数, 若是则直接返回false
        if (sum % 2 != 0) {
            return false;
        }

        // 抽象为背包问题, 容量为数组总和的一半
        int target = sum / 2;
        // 一维dp数组
        vector<int> dp(target + 1, 0);  // 初始化全为0  

        // 先遍历物品后遍历背包, 背包倒序遍历
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                // 递推公式, 该题数组数值既代表容量也代表价值
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        return dp[target] == target;
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
    int result = solution.canPartition(nums);
    cout << (result ? "true" : "false") << endl;
}
