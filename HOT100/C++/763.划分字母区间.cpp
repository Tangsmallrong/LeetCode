/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
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
    vector<int> partitionLabels(string s) {
        int hash[27];

        // 记录每个字符在字符串中的最远出现位置
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a'] = i;
        }

        // 结果数组
        vector<int> res;
        // 区间左右边界
        int left = 0, right = 0;

        // 遍历字符串
        for (int i = 0; i < s.size(); i++) {
            // 更新右边界
            right = max(right, hash[s[i] - 'a']);

            // 判断是否已经遍历到右边界
            if (i == right) {
                // 收集结果
                res.push_back(right - left + 1);

                // 更新左边界
                left = i + 1;
            }
        }

        return res;
    }
};
// @lc code=end

int main() {
    string s;
    getline(cin, s);

    Solution solution;
    vector<int> result = solution.partitionLabels(s);
    for (int num : result) {
        cout << num << endl;
    }
}
