/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
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

    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) return res;

        // 递归
        backTracking(nums, 0);
        return res;
    }

    void backTracking(vector<int>& nums, int startIndex) {
        // 收集结果(包括空集)
        res.push_back(path);

        // 递归终止条件(可省略)
        if (startIndex >= nums.size()) {
            return;
        }

        // 单层递归逻辑
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);

            // 递归
            backTracking(nums, i + 1);

            // 回溯
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
    vector<vector<int>> result = solution.subsets(nums);

    for (vector<int> res : result) {
        for (int num : res) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

