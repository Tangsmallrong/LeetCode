/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

#include <string.h>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            // int mid = (left + right) / 2;
            int mid = left + ((right - left) / 2); // 防止溢出 等同于(left + right)/2
            // (L + R) / 2 直接计算中点
            // L + (R - L) / 2 可以展开为 L/2 + R/2，这与 (L + R) / 2 是等价的
            // 这个技巧的关键在于避免了直接相加可能导致的整数溢出，通过先计算偏移量再加上起始点的方式来找到中间点

            if (target < nums[mid]) {
                right = mid - 1;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};
// @lc code=end

int main() {
    vector<int> nums;
    int target;
    string line;
    
    // 输入数组
    cout << "请输入数组（以空格分隔，回车结束）: ";
    getline(cin, line);
    stringstream ss(line);
    int number;
    while (ss >> number) {
        nums.push_back(number);
    }
    
    // 输入目标值
    cout << "请输入目标值: ";
    cin >> target;
    
    Solution solution;
    int result = solution.search(nums, target);
    
    // 输出查找结果
    if (result != -1) {
        cout << "目标值的索引: " << result << endl;
    } else {
        cout << "数组中没有找到目标值" << endl;
    }

    return 0;
}