/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
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
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        // 计算前缀积
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        // 计算后缀积, 并将其与前缀积相乘
        int suffixProduct = 1;
        for (int i = n - 2; i >= 0; i--) {
            suffixProduct *= nums[i + 1];
            res[i] *= suffixProduct;
        }

        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    int n;
    cout << "请输入数组的长度: ";
    cin >> n;

    vector<int> nums(n);
    cout << "请输入数组元素: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = solution.productExceptSelf(nums);

    cout << "数组中除自身之外其余各元素的乘积: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

// 使用两个数组实现(好理解些)-时空复杂度O(n)
// vector<int> productExceptSelf(vector<int>& nums) {
//     int n = nums.size();
//     vector<int> pre(n, 1);
//     vector<int> suf(n, 1);

//     // 计算前缀积
//     for (int i = 1; i < n; i++) {
//         pre[i] = pre[i - 1] * nums[i - 1];
//     }

//     // 计算后缀积
//     for (int i = n - 2; i >= 0; i--) {
//         suf[i] = suf[i + 1] * nums[i + 1];
//     }

//     // 计算目标值
//     for (int i = 0; i < n; i++) {
//         pre[i] *= suf[i];
//     }

//     return pre;
// }