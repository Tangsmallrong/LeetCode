/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 定义虚拟头节点, 方便操作
        ListNode *dummyHead = new ListNode(0);
        ListNode *cur = dummyHead;
        // 存储每位之和
        int sum = 0;

        // 遍历两个链表, 对每一位进行相加求和
        while (l1 || l2 || sum) {
            // 由于两个链表的长度不一定相等, 所以先判断该位的值是否需要添加两链表的元素
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            } 
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            // 存储该位的值, 结果链表的值通过两个数的和取余10得到
            cur->next = new ListNode(sum % 10);
            cur = cur->next;

            // 本次进位的值, 通过两个数的和整除10得到
            sum /= 10;
        }

        return dummyHead->next;
    }
};
// @lc code=end

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    ListNode *l1 = nullptr, *l2 = nullptr, *cur = nullptr;
    
    cout << "输入第一个链表: ";
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

    cout << "输入第二个链表: ";
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
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // 输出结果
    cout << "结果链表: ";
    cur = result;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    // 释放链表内存
    while (result != nullptr) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}