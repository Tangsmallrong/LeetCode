/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

#include <string.h>
#include <vector>
#include <unordered_set>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];  // 按照第一列的大小进行升序排序
} 

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 如果集合为空则直接返回
        if (intervals.size() == 0) return intervals;

        // 定义结果集合
        vector<vector<int>> res;

        // 先对集合中的区间排序, 使可能合并的区间相邻
        // 自定义排序规则(lambda表达式), 根据每个区间的左边界大小进行升序排列
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) { 
            return a[0] < b[0];
        }); 
        // sort(intervals.begin(), intervals.end(), compare);

        // 将第一个区间放入结果集合中
        res.push_back(intervals[0]);
        // 从第二个元素开始遍历集合, 进行重叠判断和合并操作
        for (int i = 1; i < intervals.size(); i++) {
            // 将当前遍历得到的区间的左边界与上一个区间的右边界进行比较
            // 若前者更小或等, 则说明有重叠
            if (intervals[i][0] <= res.back()[1]) {
                // 合并区间, 更新区间右边界为这两个区间右边界的较大值
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            } else {  // 无重叠则直接添加入结果集合中
                res.push_back(intervals[i]);
            }
        }
        
        return res;
    }
};
// @lc code=end

int main() {
    int n;
    cout << "请输入区间的数量: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    cout << "请输入每个区间的起始和结束位置: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    // 创建 Solution 对象并调用 merge 方法
    Solution solution;
    vector<vector<int>> result = solution.merge(intervals);

    // 输出结果
    cout << "合并后的区间为: " << endl;
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }

    return 0;
}