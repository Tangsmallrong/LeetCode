/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
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
    // 先合并数组再找中位数: 时空复杂度O(m+n)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 计算两个数组大小
        int len1 = nums1.size();
        int len2 = nums2.size();
        int i = 0, j = 0;
        int len = len1 + len2;
        vector<int> nums;

        // 合并区间
        while (i < len1 && j < len2) {
            if (nums1[i] <= nums2[j]) {
                nums.push_back(nums1[i++]);
            } else {
                nums.push_back(nums2[j++]);
            }
        }

        // 将剩余元素添加进数组中
        while (i < len1) {
            nums.push_back(nums1[i++]);
        }
        while (j < len2) {
            nums.push_back(nums2[j++]);
        }

        // 计算中位数, 注意除以 2.0
        if (len % 2 == 0) {
            return (nums[len / 2] + nums[len / 2 - 1]) / 2.0;
        } else {
            return nums[len / 2];
        }
    }
};
// @lc code=end

int main() {
    Solution solution;
    int m, n;

    cout << "请输入第一个数组的长度: ";
    cin >> m;
    vector<int> nums1(m);
    cout << "请输入第一个数组的元素: ";
    for (int i = 0; i < m; ++i) {
        cin >> nums1[i];
    }

    cout << "请输入第二个数组的长度: ";
    cin >> n;
    vector<int> nums2(n);
    cout << "请输入第二个数组的元素: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums2[i];
    }

    double result = solution.findMedianSortedArrays(nums1, nums2);
    cout << "两个正序数组的中位数是: " << result << endl;

    return 0;
}

// 递归解法 O(log(m+n)), 每次递归中排除一半的元素 难理解
// double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//     // 获取两数组的总长度
//     int n = nums1.size() + nums2.size();

//     // 分奇偶情况讨论
//     if (n  % 2 == 0) {  // 偶数
//         int left = find(nums1, 0, nums2, 0, n / 2);
//         int right = find(nums1, 0, nums2, 0, n / 2 + 1);
//         return (left + right) / 2.0;
//     }
    
//     // 奇数
//     return find(nums1, 0, nums2, 0, n / 2 + 1);
// }

// int find(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k) {
//     // 保证 len1 < len2, 即保证如果有数组空了, 一定是 len1 
//     if (nums1.size() - start1 > nums2.size() - start2) return find(nums2, start2, nums1, start1, k);

//     // 处理特殊情况 递归终止条件
//     // 若 len1 长度为 0, 则返回 len2 的第 k 个元素
//     if (nums1.size() == start1) return nums2[start2 + k - 1];
//     // 若 k = 1, 则返回两数组中最小的那个
//     if (k == 1) return min(nums1[start1], nums2[start2]);

//     // 二分查找
//     int idx1 = min((int)nums1.size(), start1 + k / 2);
//     int idx2 = start2 + k - k / 2;  // k - k / 2 确保即使 k 为奇数，两部分之和仍然等于 k

//     if (nums1[idx1 - 1] < nums2[idx2 - 1]) {  // 删除 nums1 的前 k/2 个元素
//         return find(nums1, idx1, nums2, start2, k - (idx1 - start1));
//     } else {  // 删除 nums2 的前 k/2 个元素
//         return find(nums1, start1, nums2, idx2, k - (idx2 - start2));
//     }
// }