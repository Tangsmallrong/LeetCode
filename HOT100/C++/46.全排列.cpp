/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start

#include <string.h>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) return res;

        vector<int> used(nums.size());
        backTracking(nums, used);
        return res;
    }

    void backTracking(vector<int>& nums, vector<int>& used) {
        // 递归终止条件
        if (path.size() == nums.size()) {
            // 全排列, 当该层path存储的结果大小与nums大小相同时收集结果
            res.push_back(path);
            return;
        }

        // 注意这里是排列, 所以从i=0开始遍历对所有元素, 利用 used 数组防止重复选取同一个元素
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] != 0) {
                continue;
            }

            path.push_back(nums[i]);
            used[i] = 1;

            // 递归
            backTracking(nums, used);

            // 回溯
            used[i] = 0;
            path.pop_back();
        }

        return;
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
    vector<vector<int>> result = solution.permute(nums);

    for (vector<int> res : result) {
        for (int num : res) {
            cout << num << " ";
        }
        cout << endl;
    }
}