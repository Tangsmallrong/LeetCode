/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head;
        ListNode *pre = NULL;

        while (cur != NULL) {
            ListNode *temp = cur->next;  // 先存储 cur 的下一个节点，保证不丢失后续链表
            cur->next = pre;  // 改变 cur 的下一个指针指向 pre，实现反转
            pre = cur;  // 前移 pre 和 cur 
            cur = temp;
        }

        return pre;  // 返回新的头节点，即原链表的尾节点
    }
};
// @lc code=end

int main() {
    string line;
    cout << "请输入链表节点的值（以空格分隔，回车结束）: ";
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

    Solution solution;
    ListNode *resultHead = solution.reverseList(dummy->next); // 反转链表

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


// 递归
// ListNode* reverseList(ListNode* head) {
//     return reverse(head, NULL);
// }
// ListNode* reverse(ListNode *cur, ListNode *pre) {
//     if (cur == NULL) {
//         return pre;
//     }

//     ListNode *temp = cur->next;  // 先存储下一个节点
//     cur->next = pre;  // 反转指针指向

//     return reverse(temp, cur);  // 移动视作下一层递归
// } 

// 虚拟头节点+头插法
ListNode* reverseList(ListNode* head) {
    // 创建虚拟头结点
    ListNode *dummyHead = new ListNode();

    // 遍历所有节点
    ListNode *cur = head;
    while(cur != NULL){
        ListNode *temp = cur->next;
        // 头插法
        cur->next = dummyHead->next;
        dummyHead->next = cur;

        cur = temp;
    }
    return dummyHead->next;
}