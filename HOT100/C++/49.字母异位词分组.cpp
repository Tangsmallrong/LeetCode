/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 创建哈希表
        // 键用于存储每个元素的字母序排列值, 值为符合条件的字母异位词组成的字符串数组
        unordered_map<string, vector<string>> map;

        // 遍历字符串数组, 按照规定存储于哈希表中
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];  // 存储排序前的字符串
            sort(strs[i].begin(), strs[i].end());

            // 以排序后的值为键, 排序前的为值
            map[strs[i]].push_back(str);  // 使用 push_back 方法向现有的 vector 添加新元素
        }

        // 遍历哈希表, 将哈希表拼接转换为返回值
        vector<vector<string>> vec;
        for (unordered_map<string, vector<string>>::iterator it = map.begin(); it != map.end(); it++) {
            vec.push_back(it->second);
        }

        return vec;
    }
};
// @lc code=end


int main() {
    // 输入字符串数组
    vector<string> strs;
    string input;
    cout << "请输入字符串数组（以空格分隔，回车结束）: ";
    getline(cin, input);
    istringstream iss(input);
    string word;
    while (iss >> word) {
        strs.push_back(word);
    }

    // 创建 Solution 对象并调用 groupAnagrams 方法
    Solution solution;
    vector<vector<string>> result = solution.groupAnagrams(strs);

    // 输出结果
    cout << "字母异位词组合结果: " << endl;
    for (const auto& group : result) {
        cout << "[";
        for (const auto& str : group) {
            cout << "\"" << str << "\" ";
        }
        cout << "]" << endl;
    }

    return 0;
}
