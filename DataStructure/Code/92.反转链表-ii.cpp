/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *pre = dummyHead;
        ListNode *rightNode = dummyHead;

        // 定位 pre 到 left-1 的位置
        while (--left) {
            pre = pre->next;
        }

        // 定位 rightNode 到 right 的位置
        while (right--) {
            rightNode = rightNode->next;
        }

        // 保存反转起始节点及其下一个节点, 以及 rightNode 的下一个节点
        ListNode *leftNode = pre->next;  // 反转起始节点
        ListNode *cur = leftNode->next;
        ListNode *curr = rightNode->next;  
    
        // 先将pre->next链接到rightNode, leftNode->next链接到curr
        pre->next = rightNode;
        leftNode->next = curr;

        // 执行反转
        while(cur != curr) {
            ListNode *temp = cur->next;  // 保存 cur 的下一个节点
            cur->next = leftNode;  // 反转 cur 指向 leftNode
            leftNode = cur;  // 移动 leftNode 到当前 cur
            cur = temp;  // 移动 cur 到下一个待反转节点
        }

        return dummyHead->next;
    }
};
// @lc code=end

int main() {
    cout << "请输入链表节点的值（以空格分隔，回车结束）: ";
    string line;
    getline(cin, line);
    stringstream ss(line);
    int number;

    ListNode *dummy = new ListNode(-1); // 创建一个虚拟头节点方便操作
    ListNode *current = dummy;

    // 构建链表
    while (ss >> number) {
        current->next = new ListNode(number);
        current = current->next;
    }

    int left, right;
    cout << "请输入要反转的起始位置left: ";
    cin >> left;
    cout << "请输入要反转的结束位置right: ";
    cin >> right;

    Solution solution;
    ListNode *resultHead = solution.reverseBetween(dummy->next, left, right); // 反转链表

    // 打印处理后的链表
    cout << "反转后的链表: ";
    current = resultHead;
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
    delete dummy; // 最后别忘了释放虚拟头节点的内存

    return 0;
}


