/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        // 定义虚拟头节点，其指向的下一个节点为 head
        ListNode* dummyNode = new ListNode(0, head);
        ListNode* cur = dummyNode;  // 临时节点
        

        // 遍历链表, 找到符合条件的节点
        while (cur->next != NULL) {
            if (cur->next->val == val) {  // 如果某个节点的值等于目标值
                // 当删除一个节点时，应该先保存这个节点的指针
                // 然后再改变指针指向，最后释放那个节点的内存
                // 这样可以避免内存泄漏
                ListNode* toDelete = cur->next; // 保存需要删除的节点
                cur->next = cur->next->next;  // 删除该节点
                delete toDelete; // 释放内存
            } else {
                cur = cur->next;
            }
        }

        ListNode* newHead = dummyNode->next;
        delete dummyNode; // 删除虚拟头节点
        return newHead;
    }
};
// @lc code=end

// 测试
int main() {
    string line;
    int val;

    // 输入链表节点值
    cout << "请输入链表节点的值（以空格分隔，回车结束）: ";
    getline(cin, line);
    stringstream ss(line);
    int number;

    ListNode *dummy = new ListNode(-1); // 创建一个虚拟头节点方便操作
    ListNode *current = dummy;

    while (ss >> number) {
        current->next = new ListNode(number);
        current = current->next;
    }

    // 输入要移除的元素值
    cout << "请输入要移除的元素值: ";
    cin >> val;

    Solution solution;
    ListNode *resultHead = solution.removeElements(dummy->next, val);

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
    delete dummy; // 最后别忘了释放虚拟头节点的内存

    return 0;
}

// 不使用虚拟头节点
// ListNode* removeElements(ListNode* head, int val) {
//     ListNode* cur;  // 临时节点

//     // 删除头节点
//     while (head != NULL && head->val == val) {
//             head = head->next;
//     }
    
//     cur = head;

//     // 遍历链表, 找到符合条件的节点
//     // 注意这里的循环条件需要先判断 cur 再判断 cur->next
//     // 如果颠倒顺序, 可能会导致访问一个不存在的内存地址
//     while (cur != NULL && cur->next != NULL) {
//         if (cur->next->val == val) {  // 如果某个节点的值等于目标值
//             // 当删除一个节点时，应该先保存这个节点的指针
//             // 然后再改变指针指向，最后释放那个节点的内存
//             // 这样可以避免内存泄漏
//             ListNode* toDelete = cur->next; // 保存需要删除的节点
//             cur->next = cur->next->next;  // 删除该节点
//             delete toDelete; // 释放内存
//         } else {
//             cur = cur->next;
//         }
//     }

//     return head;
// }