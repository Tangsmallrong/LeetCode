/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

#include <string.h>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // 前缀和+哈希表 O(n)
    int subarraySum(vector<int>& nums, int k) {
        // 哈希表，存储前缀和及其出现次数
        unordered_map<int, int> map;
        map[0] = 1;  // 初始化前缀和为 0 的情况
        int preSum = 0;  // 记录当前的前缀和
        int count = 0;  // 记录符合条件的子数组个数

        // 遍历数组, 将前缀和及前缀和的出现次数存储在哈希表中
        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i];  // 更新前缀和

            // 若存在子数组和为 k，则更新 count 值
            if (map.count(preSum - k)) {
                // 更新 count 值
                count += map[preSum - k];
            }

            // 存储当前前缀和的出现次数
            map[preSum] += 1;
        }

        return count;  // 返回符合条件的子数组个数
    }
};
// @lc code=end

int main() {
    int n, k;
    cout << "请输入数组的长度: ";
    cin >> n;
    cout << "请输入数组元素: ";
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "请输入目标和 k: ";
    cin >> k;

    Solution solution;
    int result = solution.subarraySum(nums, k);
    cout << "和为 " << k << " 的子数组个数是: " << result << endl;

    return 0;
}