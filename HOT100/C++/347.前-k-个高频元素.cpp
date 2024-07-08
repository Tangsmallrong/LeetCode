/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

#include <string.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        // 把元素和对应出现次数存储在哈希表中
        for (int num : nums) {
            map[num]++;
        }

        // 使用优先级队列模拟小顶堆(默认是大顶堆, 这里需要指定排序规则)
        // 第一个参数指元素类型, 第二个参数指存储元素的底层容器类型, 第三个参数指定比较规则
        priority_queue<pair<int, int>,  vector<pair<int, int>>, cmp> minHeap;
        
        // 遍历哈希表, 每次将元素push到队列中, 如果大于K则弹出
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            // unordered_map 的每个元素是一个 pair
            // it 是一个指向 pair<int, int> 的迭代器, 而 *it 是一个 pair<int, int> 类型的对象
            minHeap.push(*it);  // 将 pair<int, int> 类型的对象插入到优先队列中
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // 将队列里的元素倒序存储于结果数组并返回
        vector<int> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = minHeap.top().first;
            minHeap.pop();
        }

        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> nums;
    int k;

    cout << "请输入数组元素（以空格分隔）: ";
    string input;
    getline(cin, input);
    stringstream ss(input);
    int num;
    while (ss >> num) {
        nums.push_back(num);
    }

    cout << "请输入 k 的值: ";
    cin >> k;

    vector<int> result = solution.topKFrequent(nums, k);
    cout << "出现频率最高的 " << k << " 个元素是: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}