/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include <string.h>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int i = 0, result = INT_MAX, sum = 0; 

        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];

            // 当sum大于等于target时, 尝试通过移动左指针缩小窗口, 直到窗口内的sum小于target
            while (sum >= target) {
                int len = j - i + 1;  // 计算当前满足条件的子数组长度
                result = min(len, result);  // 更新结果
                sum -= nums[i++];  // 计算完 len 之后再移动左指针并更新sum
            }
        }

        return result == INT_MAX ? 0 : result;
    }
};
// @lc code=end

int main() {
    vector<int> nums;
    int target, result;
    string line;
    
    // 输入目标值
    cout << "请输入目标值: ";
    cin >> target;
    cin.ignore();  // 忽略掉之前读取整数后留下的换行符
    
    // 输入数组
    cout << "请输入数组（以空格分隔，回车结束）: ";
    getline(cin, line);
    stringstream ss(line);
    int number;
    while (ss >> number) {
        nums.push_back(number);
    }
    
    Solution solution;
    result = solution.minSubArrayLen(target, nums);
    
    // 输出最短子数组的长度
    cout << "最短子数组的长度: " << result << endl;

    return 0;
}


// 暴力解法-超时
// int minSubArrayLen(int target, vector<int> &nums) {
//     int minLen = INT_MAX; // 最小长度初始化为最大整数

//     for (int i = 0; i < nums.size(); i++) {
//         int sum = 0; // 每次开始新的子数组时重置sum
//         for (int j = i; j < nums.size(); j++) {
//             sum += nums[j];
//             if (sum >= target) {
//                 minLen = min(minLen, j - i + 1); // 更新最小长度
//                 break;                           // 已找到满足条件的子数组，跳出内层循环
//             }
//         }
//     }

//     if (minLen == INT_MAX) {
//         return 0; // 如果minLen没有被更新，说明没有符合条件的子数组
//     }

//     return minLen;
// }

// 更优雅的暴力解法-依旧超时
// int minSubArrayLen(int target, vector<int> &nums) {
//     int minLen = 0;

//     for (int i = 0; i < nums.size(); i++) {
//         int sum = 0;  // 每次开始新的子数组时重置 sum
//         for (int j = i; j < nums.size(); j++) {
//             sum += nums[j];
//             if (sum >= target) {
//                 int len = j - i + 1;
//                 // 处理两种情况
//                 // 一是找到的第一个满足条件的子数组长度
//                 // 二是之后找到的满足条件的更短的子数组长度
//                 // 如果minLen为0（意味着这是第一次找到满足条件的子数组）, 直接将len赋值给minLen; 否则, 将minLen更新为minLen和len中的较小值
//                 minLen = minLen == 0 ? len : min(minLen, len);
//                 break;  // 已找到满足条件的子数组，跳出内层循环
//             }
//         }
//     }

//     return minLen;
// }

// 前缀和+二分查找
// int minSubArrayLen(int target, vector<int>& nums) {
//     int length = nums.size();
//     int minLen = INT_MAX;
//     vector<int> sums(length + 1, 0);

//     // 计算前缀和
//     for (int i = 1; i <= length; ++i) {
//         sums[i] = sums[i - 1] + nums[i - 1];
//     }

//     // 遍历寻找最短子数组
//     // 对于每个可能的起点 i（通过前缀和数组表示）, 计算包含该起点且和至少为 target 的子数组的最短长度
//     for (int i = 0; i <= length; ++i) {
//         int toFind = target + sums[i];
//         // 二分查找, 找的目标值是 target + sums[i], 找到第一个使得子数组和大于等于 target 的终点 j
//         // lower_bound 返回一个指向给定序列中的一个元素的迭代器, 这个元素是序列中第一个不小于（即大于或等于）搜索值的元素
//         vector<int>::iterator bound = lower_bound(sums.begin(), sums.end(), toFind);

//         if (bound != sums.end()) {  // 如果找到
//             // 计算迭代器 bound 指向的元素在 sums 数组（或向量）中的索引
//             // 相减得两个迭代器之间的距离, 得到了 bound 指向的元素在 sums 数组中的索引位置
//             int index = bound - sums.begin();  
            
//             minLen = min(minLen, index - i);  // 更新 minLen 为找到的子数组长度 (index - i) 与当前 minLen 中的较小值
//         }
//     }
//     return minLen == INT_MAX ? 0 : minLen;
// }