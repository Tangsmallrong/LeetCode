/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

#include <string.h>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // 如果数组为空，直接返回0

        int uniqueIndex = 0; // 初始化一个变量uniqueIndex用于跟踪唯一元素的位置

        // 遍历数组，快指针j用于探索数组中的每个元素
        for (int j = 1; j < nums.size(); j++) {
            // 如果发现了一个新的唯一元素（与前一个元素不同）
            if (nums[j] != nums[uniqueIndex]) {
                uniqueIndex++; // 移动uniqueIndex到新的唯一元素的位置
                nums[uniqueIndex] = nums[j]; // 更新这个位置的值为新发现的唯一元素
            }
        }

        // 返回数组中唯一元素的个数，数组索引从0开始，因此需要加1
        return uniqueIndex + 1;
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
    
    Solution solution;
    int newLength = solution.removeDuplicates(nums);
    
    // 输出新的长度
    cout << "新的长度: " << newLength << ", nums = [";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i];
        if (i < newLength - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}