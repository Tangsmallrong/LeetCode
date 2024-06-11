/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <string.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm> 
#include <cmath>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 自底向上的归并排序
        // 先计算链表长度
        int len = 0;
        for (ListNode *cur = head; cur != nullptr; cur = cur->next) {
            len++;
        }

        // 初始把每个节点看成单独的链表, 使用步长 step 从 1 开始
        // 每次将链表分成多个长度为 step 的子链表, 并两两合并
        // step 每次 *2 直到链表的长度达到 n
        for (int step = 1; step < len; step *= 2) {
            // 定义虚拟头节点方便保存合并后的链表
            ListNode *dummyHead = new ListNode(0);
            ListNode *cur = dummyHead;

            // 计算在当前步长下需要两两合并的次数 len/(2*step)
            int cnt = ceil(1.0 * len / (2 * step));

            // 进行当前步长下的两两合并操作
            while (cnt--) {
                // 先找到需要合并的两个子链表的头节点
                ListNode *p = head;
                ListNode *q = head;
                // q 向后走 step 步即可, 注意这里需要边界判断
                for (int j = 0; j < step && q; j++) {
                    q = q->next;
                }

                // 计算下一组需要合并的子链表的头部, 方便下一轮的合并
                ListNode *next = q;
                for (int j = 0; j < step && next; j++) {
                    next = next->next;
                }

                // 合并两个长度为 step 的链表
                int left = 0, right =0;
                while (left < step && right < step && p && q) {
                    if (p->val <= q->val) {
                        cur->next = p;
                        cur = cur->next;
                        p = p->next;
                        left++;
                    } else {
                        cur->next = q;
                        cur = cur->next;
                        q = q->next;
                        right++;
                    }
                }

                // 将剩余的元素接到合并后的链表后面
                while (left < step && p) {
                    cur->next = p;
                    cur = cur->next;
                    p = p->next;
                    left++;
                } 
                while (right < step && q) {
                    cur->next = q;
                    cur = cur->next;
                    q = q->next;
                    right++;
                }

                // 把 head 移动到当前步长下的下一组需要合并的链表的头部
                head = next;
            }

            // 把 cur->next 置空, 避免链表成环
            cur->next = nullptr;
            // 更新头节点
            head = dummyHead->next;
        }

        return head;
    }
};
// @lc code=end

int main() {
    int n;
    cout << "请输入链表节点数: ";
    cin >> n;

    if (n == 0) {
        cout << "排序后的链表: 空" << endl;
        return 0;
    }

    cout << "请输入链表节点值: ";
    int val;
    cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* current = head;

    for (int i = 1; i < n; ++i) {
        std::cin >> val;
        current->next = new ListNode(val);
        current = current->next;
    }

    // 调用 sortList 函数排序链表
    Solution solution;
    ListNode* sortedHead = solution.sortList(head);

    // 输出排序后的链表
    cout << "排序后的链表: ";
    while (sortedHead) {
        cout << sortedHead->val << " ";
        sortedHead = sortedHead->next;
    }

    // 释放链表内存
    while (sortedHead) {
        ListNode* temp = sortedHead;
        sortedHead = sortedHead->next;
        delete temp;
    }

    return 0;
}
