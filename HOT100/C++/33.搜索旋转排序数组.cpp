/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
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
    // 闭区间写法
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        // 通过二分先找到旋转后的分界点
        // 分界点前的数均大于分界点后的数
        // 使用左闭右闭区间的写法
        while (left <= right) {  
            int mid = left + (right - left) / 2;

            if (nums[mid] >= nums[0]) {  // 分界点在后面
                left = mid + 1;
            } else {  // 分界点在前面, 继续向左搜索
                right = mid - 1;
            }
        }

        // 判断目标值在分界点的左边还是右边, 确定搜索范围
        if (target >= nums[0]) {  // 左边, 这边取等于, 因为nums[0]必在左边
            left = 0;
        } else {  // 右边
            right = nums.size() - 1;
        }

        // 在搜索范围内进行二分查找, 左闭右闭区间
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {  
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1; 
    }
};
// @lc code=end

int main() {
    Solution sol;
    vector<int> nums;
    int target;
    
    cout << "请输入旋转排序数组（例如：4 5 6 7 0 1 2）：";
    int num;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.get() == '\n') break;
    }

    cout << "请输入目标值：";
    cin >> target;

    int result = sol.search(nums, target);
    if (result != -1) {
        cout << "目标值在数组中的索引为：" << result << endl;
    } else {
        cout << "目标值不在数组中" << endl;
    }

    return 0;
}

