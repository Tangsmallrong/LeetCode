/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
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
    bool canJump(vector<int>& nums) {
        int cover = 0;

        if (nums.size() == 1) return true;

        for (int i = 0; i <= cover; i++) {
            cover = max(cover, i + nums[i]);

            if (cover >= nums.size() - 1) {
                return true;
            }
        }

        return false;
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
    int result = solution.canJump(nums);
    cout << (result ? "true" : "false") << endl;
}
