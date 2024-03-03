/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

#include <string.h>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;  // 初始化i，用于指向当前需要插入非零元素的位置

        // 遍历数组，寻找所有非零元素   
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                // 如果当前元素不是0，将其移动到i的位置，然后i递增
                nums[i++] = nums[j];
            }
        }

        // 在处理完所有非零元素后，i的位置及其之后的所有位置都应该填充0
        for ( ; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
// @lc code=end

int main() {
    vector<int> nums;
    string line;
    
    cout << "请输入数组（以空格分隔，回车结束）: ";
    getline(cin, line);
    stringstream ss(line);
    int number;
    while (ss >> number) {
        nums.push_back(number);
    }
    
    Solution solution;
    solution.moveZeroes(nums);
    
    cout << "处理后的数组: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

