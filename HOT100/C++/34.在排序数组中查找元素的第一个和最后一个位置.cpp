/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
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
    vector<int> searchRange(vector<int>& nums, int target) {
        // 考虑特殊情况：如果数组为空，返回 [-1, -1]
        if (nums.size() == 0) return {-1, -1};

        // 考虑区间左开右开的写法
        // left 和 right 分别初始化为 -1 和 nums.size()，表示左开右开的搜索区间
        int left = -1;
        int right = nums.size();
        int minIndex = -1;

        // 通过二分查找，找出目标值的最左边界
        while (left + 1 < right) {  // 区间不为空 (left, right)
            int mid = left + (right - left) / 2;

            // 更新区间 (mid, right)
            if (nums[mid] < target) {
                left = mid;
            }
            else {
                // 更新区间为 (left, mid)
                right = mid;
            } 
        }

        // 检查是否找到了目标值
        // 如果 right 没有越界且 nums[right] 等于目标值，更新 minIndex
        if (right < nums.size() && nums[right] == target) minIndex = right;
        else return {-1, -1};

        // 重置 left 和 right，准备查找目标值的最右边界
        left = right - 1, right = nums.size();
        // 通过二分查找，找出目标值的最右边界
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;

            // 更新区间 (mid, right)
            if (nums[mid] <= target) {
                left = mid;
            }
            else {  // 更新区间为 (left, mid)
                right = mid;
            }
        }

        // 返回目标值的起始和结束位置
        return {minIndex, left};
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> nums;
    int target, n;

    // 输入数组长度和数组元素
    cout << "请输入数组的长度: ";
    cin >> n;

    // 输入数组元素
    cout << "请输入数组元素: ";
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    // 输入目标值
    cout << "请输入目标值: ";
    cin >> target;

    // 调用searchRange函数
    vector<int> result = solution.searchRange(nums, target);

    // 输出结果
    cout << "目标值的起始位置和结束位置为: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}