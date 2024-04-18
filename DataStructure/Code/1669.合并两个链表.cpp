/*
 * @lc app=leetcode.cn id=1669 lang=cpp
 *
 * [1669] 合并两个链表
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *dummyHead = new ListNode(0, list1);
        ListNode *cur1 = dummyHead;
        ListNode *cur2 = list2;

        // 移动cur1到索引a的前一个节点
       for (int i = 0; i < a; i++) {
            cur1 = cur1->next;
        } 

        ListNode *cur = cur1;
        for (int i = a; i <= b; i++) {  // 移动cur到索引b的节点
            cur = cur->next;
        }

        // 遍历到list2的末尾
        while (cur2->next != NULL) {
            cur2 = cur2->next;
        }

        // 链接list2到list1
        cur1->next = list2;
        cur2->next = cur->next;
        cur->next = NULL;

        return dummyHead->next;
    }
};
// @lc code=end

int main() {
    cout << "请输入链表1的节点值（以空格分隔，回车结束）: ";
    string line1;
    getline(cin, line1);
    stringstream ss1(line1);
    int number;

    ListNode *dummy1 = new ListNode(-1);
    ListNode *current1 = dummy1;

    // 构建链表1
    while (ss1 >> number) {
        current1->next = new ListNode(number);
        current1 = current1->next;
    }

    cout << "请输入链表2的节点值（以空格分隔，回车结束）: ";
    string line2;
    getline(cin, line2);
    stringstream ss2(line2);

    ListNode *dummy2 = new ListNode(-1);
    ListNode *current2 = dummy2;

    // 构建链表2
    while (ss2 >> number) {
        current2->next = new ListNode(number);
        current2 = current2->next;
    }

    int a, b;
    cout << "请输入要删除的起始索引a: ";
    cin >> a;
    cout << "请输入要删除的结束索引b: ";
    cin >> b;

    // 合并链表
    Solution solution;
    ListNode *resultHead = solution.mergeInBetween(dummy1->next, a, b, dummy2->next);

    // 打印处理后的链表
    cout << "处理后的链表: ";
    ListNode *current = resultHead;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // 释放链表内存
    current = resultHead;
    while (current != nullptr) {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }
    delete dummy1; // 释放链表1的虚拟头节点
    delete dummy2; // 释放链表2的虚拟头节点

    return 0;
}