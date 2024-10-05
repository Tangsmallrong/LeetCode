/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

#include <string.h>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 将字典存储到哈希表中方便查找
        unordered_set<string> set(wordDict.begin(), wordDict.end());

        int n = s.size();
        // 定义dp数组
        vector<bool> dp(n + 1, false);

        // 初始化
        dp[0] = true;

        // 遍历
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                string sub = s.substr(j, i - j);
                if (dp[j] && set.find(sub) != set.end()) {
                    dp[i] = true;
                    break;  // 提前终止, 已找到拆分方法
                }
            }
        }

        return dp[n];
    }
};
// @lc code=end

int main() {
    // 读取字符串 s
    string s;
    getline(cin, s);

    // 读取字典长度
    int wordDictSize;
    cin >> wordDictSize;
    cin.ignore();  // 忽略换行符

    // 读取字典内容
    vector<string> wordDict(wordDictSize);
    for (int i = 0; i < wordDictSize; i++) {
        getline(cin, wordDict[i]);
    }

    Solution solution;
    // 输出结果
    if (solution.wordBreak(s, wordDict)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}