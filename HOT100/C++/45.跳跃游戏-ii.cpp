/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
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
    int jump(vector<int>& nums) {
        int maxPos = 0;
        int end = 0;
        int res = 0;  // 记录跳跃次数

        // 遍历数组
        for (int i = 0; i < nums.size() - 1; i++) {
            // 更新最远能达到的位置
            maxPos = max(maxPos, i + nums[i]);

            // 若已到达右边界
            if (i == end) {
                // 继续跳
                res++;

                // 更新右边界
                end = maxPos;
            }
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
    int result = solution.jump(nums);
    cout << result << endl;
}

