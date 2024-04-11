/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        // 创建虚拟头节点, 指向原链表的头节点, 简化边界处理
        ListNode *dummyHead = new ListNode(0, head);
        // 初始化用于遍历的 cur 指针, 指向虚拟头节点
        ListNode *cur = dummyHead;

        // 循环条件: 当前节点的下一个节点和下下个节点都不能为 NULL
        while (cur->next != NULL && cur->next->next != NULL) {
            // temp 指向当前要交换的第一个节点
            ListNode *temp = cur->next;
            // temp1 指向当前要交换的第二个节点的下一个节点
            ListNode *temp1 = cur->next->next->next;

            // 将 cur 的下一个节点指向第二个要交换的节点
            cur->next = cur->next->next;

            // 第二个节点的 next 指向第一个节点, 完成两个节点的交换
            cur->next->next = temp;

            // 第一个节点的 next 指向原第二个节点的下一个节点, 连接后续节点
            temp->next = temp1;

            // cur 移动两个位置, 指向下一个要交换的前一个节点
            cur = cur->next->next;
        }

        // 返回虚拟头结点的下一个节点, 即新的头节点
        ListNode* ans = dummyHead->next;
        delete dummyHead;
        return ans;
    }
};
// @lc code=end


int main() {
    string line;
    cout << "请输入链表节点的值（以空格分隔，回车结束）: ";
    getline(cin, line);
    stringstream ss(line);
    int number;

    ListNode *dummy = new ListNode(-1);  // 创建一个虚拟头节点方便操作
    ListNode *current = dummy;

    // 构建链表
    while (ss >> number) {
        current->next = new ListNode(number);
        current = current->next;
    }

    Solution solution;
    ListNode *resultHead = solution.swapPairs(dummy->next);  // 交换链表中的节点

    // 打印处理后的链表
    cout << "处理后的链表: ";
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
    delete dummy;  // 别忘了释放虚拟头节点的内存

    return 0;
}

// 递归-难理解
// ListNode* swapPairs(ListNode* head) {
//     // 如果头节点为空，或者头节点的下一个节点为空，直接返回头节点
//     if (head == NULL || head->next == NULL) {
//         return head;
//     }
//     // 获取头节点的下一个节点，这将是交换后的新头节点
//     ListNode* newHead = head->next;
    
//     // 递归调用swapPairs，从头节点的下一个节点的下一个节点开始（即从第三个节点开始）
//     // 这个调用将处理剩下的链表，并返回交换后的部分的头节点
//     // 将头节点的next指向这个返回的头节点，实现将当前对的第一个节点连接到交换后的剩余链表部分
//     head->next = swapPairs(newHead->next);
    
//     // 将新头节点的next指向当前头节点，完成这两个节点的交换
//     newHead->next = head;
    
//     // 返回新的头节点，即原来的头节点的下一个节点
//     return newHead;
// }


// 可以少存一个 temp 的写法
// ListNode* swapPairs(ListNode* head) {
//     // 创建虚拟头节点, 指向原链表的头节点, 简化边界处理
//     ListNode *dummyHead = new ListNode(0, head);
//     // 初始化用于遍历的 cur 指针, 指向虚拟头节点
//     ListNode *cur = dummyHead;

//     // 循环条件: 当前节点的下一个节点和下下个节点都不能为 NULL
//     while (cur->next != NULL && cur->next->next != NULL) {
//         // temp 指向当前要交换的第一个节点
//         ListNode *temp = cur->next;

//         // 将 cur 的下一个节点指向第二个要交换的节点
//         cur->next = cur->next->next;

//         // 先将第一个节点的 next 指向原第二个节点的下一个节点, 连接后续节点
//         temp->next = cur->next->next;

//         // 再将第二个节点的 next 指向第一个节点, 完成两个节点的交换
//         cur->next = temp;

//         // cur 移动两个位置, 指向下一个要交换的前一个节点
//         cur = cur->next->next;
//     }

//     // 返回虚拟头结点的下一个节点, 即新的头节点
//     return dummyHead->next;
// }