/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

#include <string.h>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size);  // 为 result 向量预分配足够的空间, 对于整型来说默认初始化为 0
        // vector<int> result;
        int k = size - 1, i = 0, j = k;
        
        while (i <= j) {
            if (pow(nums[i], 2) > pow(nums[j], 2)) {
                // vector 直接通过索引赋值前, 需要确保该位置是有效的, 即该位置已经被分配内存
                // 高效的解决方案是先为 result 向量预分配足够的空间, 然后再通过索引赋值
                result[k--] = pow(nums[i], 2);

                // 也可以不预先分配, 使用 insert 方法在 vector 开始处插入元素
                // 但频繁地在 vector 的开始处插入元素性能较差, 因为这会导致已有元素多次移动
                // result.insert(result.begin(), pow(nums[i], 2));
                i++;
            } else {
                result[k--] = pow(nums[j], 2);
                // result.insert(result.begin(), pow(nums[j], 2));
                j--;
            }
        }

        return result;
    }
};
// @lc code=end

int main() {
    vector<int> nums;
    string line;
    
    // 输入数组
    cout << "请输入数组（以空格分隔，回车结束）: ";
    getline(cin, line);
    stringstream ss(line);
    int number;
    while (ss >> number) {
        nums.push_back(number);
    }
    
    // 调用 sortedSquares 函数并输出结果
    Solution solution;
    vector<int> result = solution.sortedSquares(nums);
    
    cout << "平方后的数组（非递减顺序）: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}