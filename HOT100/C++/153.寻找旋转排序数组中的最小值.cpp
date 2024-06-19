/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
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
    int findMin(vector<int>& nums) {
        // 旋转点左边一定大于右边
        // 二分查找找到旋转点即可, 此处使用开区间写法
        int left = -1;
        int right = nums.size();

        while (left + 1 < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] >= nums[0]) {
                left = mid;
            } else {
                right = mid;
            }
        }

        return right < nums.size() ? nums[right] : nums[0];
    }
};
// @lc code=end

int main() {
    int n;
    cout << "请输入数组的长度: ";
    cin >> n;

    vector<int> nums(n);
    cout << "请输入数组元素: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution solution;
    int result = solution.findMin(nums);

    cout << "数组中的最小元素是: " << result << endl;

    return 0;
}