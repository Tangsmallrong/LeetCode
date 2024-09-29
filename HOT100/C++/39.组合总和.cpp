/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
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
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return res;

        // 递归
        backTracking(candidates, target, 0, 0);
        return res;
    }

    void backTracking(vector<int>& candidates, int target, int sum, int startIndex) {
        // 递归终止条件
        if (sum > target) return;
        if (sum == target) {
            res.push_back(path);
            return;
        }

        // 单层递归逻辑
        for (int i = startIndex; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            sum += candidates[i];

            // 递归
            backTracking(candidates, target, sum, i);

            // 回溯
            sum -= path[path.size() - 1];
            path.pop_back();
        }
    }
};
// @lc code=end

int main() {
    // 读取输入
    string line;
    getline(cin, line);
    istringstream ss1(line);
    vector<int> candidates;
    int num;
    while (ss1 >> num) {
        candidates.push_back(num);
    }
    int target;
    cin >> target;

    Solution solution;
    vector<vector<int>> combination = solution.combinationSum(candidates, target);

    for (vector<int> res : combination) {
        for (int num : res) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}