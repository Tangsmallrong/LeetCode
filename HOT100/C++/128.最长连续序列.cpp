/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

#include <string.h>
#include <vector>
#include <unordered_set>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 将数组存储在哈希表中(去重, 方便查找)
        unordered_set<int> set(nums.begin(), nums.end());
        int ans = 0;

        // foreach 遍历哈希表, 先找起点, 再求片段长度
        for (int num : set) {
            if (!set.count(num - 1)) {  // 如果是起点
                int x = num + 1;  // 下一个值
                while (set.count(x)) {  // 如果存在下一个值
                    x++;  // 循环继续判断后续的值是否还是存在
                }
                // 更新连续序列的长度
                ans = max(ans, x - num);
            }
        }

        return ans;
    }
};
// @lc code=end

int main() {
    // 创建 Solution 对象
    Solution solution;

    // 输入整数数组
    string input;
    cout << "请输入整数数组（以空格分隔，回车结束）: ";
    getline(cin, input);
    istringstream iss(input);
    vector<int> nums;
    int num;
    while (iss >> num) {
        nums.push_back(num);
    }

    // 调用 longestConsecutive 方法
    int result = solution.longestConsecutive(nums);

    // 输出结果
    cout << "最长连续序列的长度为: " << result << endl;

    return 0;
}

