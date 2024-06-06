/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
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
    vector<int> findAnagrams(string s, string p) {
        // 创建两个 map, 分别用于存储当前窗口的字符及其出现次数以及 p 字符串中每个字符的出现次数
        unordered_map<char, int> win, need;
        vector<int> res;

        // 将 p 字符串中的每个字符及其出现次数映射到 map 里
        for (char c : p) {
            need[c] += 1;  // 插入一个新的键, 值为 int 的默认值, 通常为 0
        }

        // 双指针滑动窗口遍历 s 字符串
        int left = 0, right = 0;
        int count = 0;  // 用于判断窗口中的字符是否满足条件
        while (right < s.size()) {
            char c = s[right];  
            right++;  // 右指针后移

            if (need.count(c)) {  // 如果 p 串里包含该字符
                win[c]++;  
                // 判断 map 中的值是否相等
                if (need[c] == win[c]) {
                    count++;  // 更新窗口中的字符计数
                }
            } 

            // 判断是否需要更新左窗口
            // 如果当前窗口的大小等于 p 的长度, 检查窗口内的字符是否满足要求
            while (right - left >= p.size()) {
                // 更新左窗口前判断当前的滑动窗口是否符合要求, 符合则添加到集合中
                if (count == need.size()) {
                    res.push_back(left);
                }

                char c = s[left];
                left++;  // 左指针右移，缩小窗口

                if (need.count(c)) {
                    if (need[c] == win[c]) {
                        count--;
                    }
                    win[c]--;
                }
            }
        } 

        return res;
    }
};
// @lc code=end

int main() {
    string s, p;

    // 输入第一个字符串
    cout << "请输入第一个字符串（回车结束）: ";
    getline(cin, s);

    // 输入第二个字符串
    cout << "请输入第二个字符串（回车结束）: ";
    getline(cin, p);

    Solution solution;
    vector<int> result = solution.findAnagrams(s, p);

    // 输出结果
    cout << "结果索引为: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}