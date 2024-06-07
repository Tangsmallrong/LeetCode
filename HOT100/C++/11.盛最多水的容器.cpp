/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
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
    int maxArea(vector<int>& height) {
        // 定义头尾双指针
        int left = 0, right = height.size() - 1;
        // 最大盛水面积
        int area = 0;

        // 遍历数组, 直到头尾指针相遇
        while (left < right) {
            // 计算当前盛水面积, 判断是否需要更新最大盛水面积
            // 当前盛水面积的高度为双指针指向的较矮的元素, 宽度为双指针指向的两下标之间的距离
            area = max(area, min(height[left], height[right]) * (right - left));

            // 移动指向较小数字的指针
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return area;
    }
};
// @lc code=end

int main() {
    int n;
    cout << "请输入数组的长度: ";
    cin >> n;

    vector<int> height(n);
    cout << "请输入数组元素，以空格分隔: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    // 创建 Solution 对象并调用 maxArea 方法
    Solution solution;
    int result = solution.maxArea(height);

    // 输出结果
    cout << "可以容纳的最大水量为: " << result << endl;

    return 0;
}