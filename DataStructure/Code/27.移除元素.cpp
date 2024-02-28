/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

#include <string.h>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
                // slow++;
            }
        }

        return slow;
    }
};
// @lc code=end

int main() {
    vector<int> nums;
    int val, length;
    string line;
    
    // 输入数组
    cout << "请输入数组（以空格分隔，回车结束）: ";
    getline(cin, line);
    stringstream ss(line);
    int number;
    while (ss >> number) {
        nums.push_back(number);
    }
    
    // 输入要移除的元素
    cout << "请输入要移除的元素: ";
    cin >> val;
    
    Solution solution;
    length = solution.removeElement(nums, val);
    
    // 输出处理后的数组长度
    cout << "处理后的数组长度: " << length << endl;
    
    // 输出处理后的数组内容
    cout << "处理后的数组: ";
    for (int i = 0; i < length; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}