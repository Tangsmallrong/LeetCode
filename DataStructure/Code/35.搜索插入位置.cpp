/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

#include <string.h>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;  // 初始化左右指针

        while (l <= r) {  // 当左指针不超过右指针时循环
            int mid = r + (l - r) / 2;  // 计算中间位置

            if (target < nums[mid]) {
                r = mid - 1;
            } else if (target > nums[mid]) {
                l = mid + 1;
            } else {
                return mid;
            }
        }
        // 如果未找到目标值，返回目标值应该被插入的位置 l 或者 r+1
        return l;  
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
    int result = solution.searchInsert(nums, target);
    
    // 输出查找结果
    cout << "目标值的索引或应该插入的位置: " << result << endl;

    return 0;
}

