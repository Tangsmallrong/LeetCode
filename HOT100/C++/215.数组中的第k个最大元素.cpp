/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

#include <string.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

// @lc code=start
class Solution {
public:
    // 快排
    int findKthLargest(vector<int>& nums, int k) {
       int n = nums.size();
       int target = n - k;  // 第1大的数下标为len-1, 第k大的数下标为len-k
       int left = 0;
       int right = n - 1;

        while (true) {
            int pivotIndex = partition(nums, left, right);
            if (pivotIndex == target) {
                return nums[pivotIndex];
            } else if (pivotIndex < target) {
                // 查找后半段
                left = pivotIndex + 1;
            } else {
                // 查找前半段
                right = pivotIndex - 1;
            }
       }
    }

    // 分区
    int partition(vector<int>& nums, int left, int right) {
        // 随机选择基准元素
        int randomIndex = left + rand() % (right - left + 1);
        swap(nums, left, randomIndex);

        int pivot = nums[left];
        int small = left + 1;
        int big = right;

        while (true) {
            while (small <= big && nums[small] < pivot) {
                small++;  // 若前半部分小于基准元素, 指针++
            }
            while (small <= big && nums[big] > pivot) {
                big--;  // 若后半部分大于基准元素, 指针--
            }

            if (small >= big) {
                break;
            }
            
            // 若前半部分大于基准/后半部分小于基准, 交换
            swap(nums, small, big);
            small++;
            big--;
        }

        swap(nums, left, big);
        return big;
    }

    // 注意是引用传递
    void swap(vector<int>& nums, int idx1, int idx2) {
        int temp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = temp;
    }
};
// @lc code=end

int main() {
    Solution solution;
    int n, k;
    cout << "请输入元素个数: ";
    cin >> n;

    vector<int> nums(n);
    cout << "请输入元素: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "请输入 k 的值: ";
    cin >> k;

    srand(time(0));  // 设置随机数种子
    int result = solution.findKthLargest(nums, k);
    cout << "第 " << k << " 大的元素是: " << result << endl;
    
    return 0;
}

// 使用最小堆解决 时间复杂度 O(nlogk)
// int findKthLargest(vector<int>& nums, int k) {
//     // 定义优先队列(最小堆)
//     priority_queue<int, vector<int>, greater<int>> maxHeap;

//     // 遍历数组
//     for (int num : nums) {
//         maxHeap.push(num);

//         // 如果堆的大小超过k, 则弹出堆顶元素
//         if (maxHeap.size() > k) {
//             maxHeap.pop();
//         }
//     }

//     // 堆顶元素即为第k大的元素
//     return maxHeap.top();
// }