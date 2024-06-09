/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 创建虚拟头节点, 便于操作
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;

        // 遍历两个链表, 直到其中有链表遍历结束
        while (list1 && list2) {
            // 每次选取两个链表指针中指向的值较小的那个值放入结果链表中
            // 并将较小的值所在的链表的指针后移
            if (list1->val <= list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }

            // 将结果链表的指针后移, 方便后续插入
            cur = cur->next;
        }

        // 最后判断是否有没遍历完的链表, 直接连接到结果链表末尾
        cur->next = list1 ? list1 : list2;

        return dummy->next;
    }
};
// @lc code=end

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    ListNode *l1 = NULL, *l2 = NULL, *cur = NULL;
    for (int i = 0; i < n1; ++i) {
        int val;
        cin >> val;
        if (!l1) {
            l1 = new ListNode(val);
            cur = l1;
        } else {
            cur->next = new ListNode(val);
            cur = cur->next;
        }
    }

    for (int i = 0; i < n2; ++i) {
        int val;
        cin >> val;
        if (!l2) {
            l2 = new ListNode(val);
            cur = l2;
        } else {
            cur->next = new ListNode(val);
            cur = cur->next;
        }
    }

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(l1, l2);

    // 输出合并后的链表
    cur = mergedList;
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    // 释放链表内存
    while (mergedList) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}