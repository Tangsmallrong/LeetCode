/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <string.h>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;  // 创建哈希表

        // 遍历数组
        for (int i = 0; i < nums.size(); i++) {
            // 每个数需要配对的值
            int num = target - nums[i];

            // 查找哈希表是否存在对应的值
            if (map.find(num) != map.end()) {
                // 找到, 返回索引
                return {map[num], i};
            }

            // 找不到则插入哈希表, 键为数值, 值为下表
            map.insert({nums[i], i});  // map[nums[i]] = i;
        }  

        // 找不到满足条件的数对，返回空向量
        return {};
    }
};
// @lc code=end


int main() {
    string input;
    int target;

    // 输入整数数组
    cout << "请输入整数数组（以空格分隔，回车结束）: ";
    getline(cin, input);
    istringstream iss(input);
    vector<int> nums;
    int num;
    while (iss >> num) {
        nums.push_back(num);
    }

    // 输入目标值
    cout << "请输入目标值: ";
    cin >> target;

    Solution solution;
    vector<int> result = solution.twoSum(nums, target);

    // 输出结果
    if (!result.empty()) {
        cout << "两个数的索引为: " << result[0] << " 和 " << result[1] << endl;
    } else {
        cout << "没有找到满足条件的两个数。" << endl;
    }

    return 0;
}


// 暴力双层 for 循环
// vector<int> twoSum(vector<int>& nums, int target) {
//     int len = nums.size();  // 获取数组长度
//     vector<int> vec;  // 用于存储结果的向量

//     // 双重循环遍历数组中的每一对元素
//     for (int i = 0; i < len; i++) {
//         for (int j = i + 1; j < len; j++) {
//             // 计算两数之和
//             int sum = nums[i] + nums[j];

//             // 如果和等于目标值，返回两个数的索引
//             if (sum == target) {
//                 vec = {i, j};
//                 return vec;
//             }
//             // 不等于目标值的情况下继续检查其他组合
//         }
//     }

//     // 如果没有找到满足条件的数对，返回空向量
//     return vec;
// }