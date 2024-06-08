/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
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
    void rotate(vector<int>& nums, int k) {
        // 对 k 进行取余, 防止其超出数组长度
        k %= nums.size();

        // 利用3次翻转代替轮转
        // 先对整个数组进行翻转
        reverse(nums.begin(), nums.end());

        // 再分别对数组的前k个元素和后n-k个元素进行翻转
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
// @lc code=end

int main() {
    int n, k;
    cout << "请输入数组的长度: ";
    cin >> n;

    vector<int> nums(n);
    cout << "请输入数组元素: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "请输入轮转的次数: ";
    cin >> k;

    Solution solution;
    solution.rotate(nums, k);

    // 输出结果
    cout << "轮转后的数组为: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// 暴力法 时空复杂度为 O(n)
// void rotate(vector<int>& nums, int k) {
//     // 定义一个新数组
//     int n = nums.size();
//     vector<int> res(n);

//     // 根据轮换规律赋值
//     for (int i = 0; i < n; i++) {
//         res[(i + k) % n] = nums[i];
//     }

//     for (int i = 0; i < n; i++) {
//         nums[i] = res[i];
//     }
// }