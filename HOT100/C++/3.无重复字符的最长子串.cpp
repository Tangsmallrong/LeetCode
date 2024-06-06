/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
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
    int lengthOfLongestSubstring(string s) {
        // 定义数组用于存储每个元素的上一次出现位置, 初始化为-1
        // 下标对应 ASCII 码值, 值即为元素在字符串中最近一次出现的下标
        vector<int> pos(128, -1);
        int len = 0;

        // 遍历字符串, 利用滑动窗口判断不重复子串的长度
        for (int i = 0, j = 0; i < s.size(); i++) {
            // 根据元素上次出现位置来更新滑动窗口的左边界
            // 若滑动窗口内有重复字符, 则为上次出现的位置的下一个位置
            j = max(j, pos[s[i]] + 1);

            // 更新最长子串的长度
            len = max(len, i - j + 1);

            // 更新所遍历的元素的位置
            pos[s[i]] = i;
        }

        return len;
    }
};
// @lc code=end

int main() {
    // 输入字符串
    string s;
    cout << "请输入一个字符串: ";
    getline(cin, s);

    Solution solution;
    int result = solution.lengthOfLongestSubstring(s);

    // 输出结果
    cout << "最长不重复子串的长度为: " << result << endl;

    return 0;
}