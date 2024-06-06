/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 先对数组进行排序
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        // 双指针遍历数组
        for (int i = 0; i < nums.size(); i++) {
            // 剪枝, 若排序后最小的值都大于0就直接返回
            if (nums[i] > 0) return res;  

            // 对第一个数进行去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            // 滑动窗口, 确定另外两个数
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                } else {
                    res.push_back(vector<int> {nums[i], nums[left], nums[right]});

                    // 收集成功后对另外两个数进行去重
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    } 

                    // 移动指针以寻找新的组合
                    right--;
                    left++;
                } 
            }
        }

        return res;
    }
};
// @lc code=end

int main() {
    int n;
    cout << "请输入数组的长度: ";
    cin >> n;

    vector<int> nums(n);
    cout << "请输入数组元素，以空格分隔: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    vector<vector<int>> result = solution.threeSum(nums);

    // 输出结果
    cout << "所有和为 0 的三元组为: " << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
