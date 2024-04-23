/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
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
    bool isAnagram(string s, string t) {
        // 如果两字符串长度不相同，直接返回false，因为字母异位词的长度必定相同
        if (s.size() != t.size()) return false;

        // 初始化一个大小为26的数组来存储每个字母的计数
        vector<int> hash(26); 

        // 遍历字符串s，统计每个字符的出现次数
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a'] += 1;  // 'a'到'z'的ASCII值连续，s[i]-'a'得到索引0到25
        }

        // 遍历字符串t，减少hash数组中对应字符的计数
        for (int i = 0; i < t.size(); i++) {
            hash[t[i] - 'a'] -= 1;  // 对每个字符，减少对应的计数
        }

        // 检查hash数组是否所有元素都是0
        for (int i = 0; i < hash.size(); i++) {
            if (hash[i] != 0) {
                return false;  // 如果有任何一个字符的计数不为0，说明s和t不是字母异位词
            }
        }

        // 如果所有字符计数都是0，返回true
        return true;
    }
};
// @lc code=end

int main() {
    string s, t;

    // 输入第一个字符串
    cout << "请输入第一个字符串（回车结束）: ";
    getline(cin, s);

    // 输入第二个字符串
    cout << "请输入第二个字符串（回车结束）: ";
    getline(cin, t);

    Solution solution;
    bool result = solution.isAnagram(s, t);

    // 输出结果
    if (result) {
        cout << "两个字符串是字母异位词。" << endl;
    } else {
        cout << "两个字符串不是字母异位词。" << endl;
    }

    return 0;
}

// 考虑 unicode 字符的哈希法 => 哈希表
bool isAnagram(string s, string t) {
    // 如果两字符串长度不相同，则直接返回false
    if (s.length() != t.length()) return false;

    unordered_map<char, int> count; // 使用 unordered_map 来计数

    // 增加s中每个字符的计数
    for (char c : s) {
        count[c]++;
    }

    // 减少t中每个字符的计数
    for (char c : t) {
        count[c]--;
        // 如果某个字符的计数变为负数，说明t中该字符出现的次数比s中多
        if (count[c] < 0) {
            return false;  // 剪枝
        }
    }

    // 检查哈希表中是否所有计数都归零
    for (auto& pair : count) {  // auto 关键字用于自动推导变量的类型，auto& 通过引用来访问元素
        if (pair.second != 0) {
            return false; // 如果有计数不为0，说明两个字符串不是字母异位词
        }
    }
    // for (unordered_map<char, int>::const_iterator it = count.begin(); it != count.end(); ++it) {
    //     if (it->second != 0) {
    //         return false; // 如果有计数不为0，说明两个字符串不是字母异位词
    //     }
    // }

    return true; // 所有计数为0，说明是字母异位词
}

// 排序比较
// bool isAnagram(string s, string t) {
//     // 如果两字符串长度不相同，直接返回false
//     if (s.size() != t.size()) return false;

//     // 排序两个字符串
//     sort(s.begin(), s.end());
//     sort(t.begin(), t.end());

//     // 比较排序后的字符串
//     return s == t;
// }

// 双重 for 遍历的暴力解法 => 超时
// bool isAnagram(string s, string t) {
//     if (s.length() != t.length()) return false;
    
//     vector<bool> used(t.length(), false);  // 用来记录`t`中的字符是否已被匹配
    
//     for (int i = 0; i < s.length(); ++i) {
//         bool found = false;
//         for (int j = 0; j < t.length(); ++j) {
//             if (s[i] == t[j] && !used[j]) { // 找到匹配的字符且未被使用
//                 used[j] = true;             // 标记为已使用
//                 found = true;
//                 break;
//             }
//         }
//         if (!found) return false;           // 如果`s[i]`找不到匹配，则直接返回false
//     }

//     return true;  // 所有字符都匹配成功
// }
