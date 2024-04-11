/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 创建虚拟头节点指向原链表的头节点
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *pre = dummyHead;  // 用于指向需要删除节点的前一个节点
        ListNode *cur = dummyHead;  // 用于遍历的指针
        int count = 0;

        // 遍历链表到尾部, 帮助 pre 指针指向倒数第n+1个节点
        while (cur->next != NULL) {
            if (count != n) {  
                count++;
            } else {
                // 当 count 达到 n 时，pre 开始移动
                // 这样当 cur 到达链表末尾时，pre 恰好指向倒数第 n+1 个节点。
                pre = pre->next;
            }

            cur = cur->next;
        }

        // if (count != n) {
        //     return head;
        // }
        ListNode *toDelete = pre->next;
        pre->next = pre->next->next;
        delete toDelete;

        ListNode *ans = dummyHead->next;
        delete dummyHead;
        return ans;
    }
};
// @lc code=end

int main() {
    cout << "请输入链表节点的值（以空格分隔，回车结束）: ";
    string line;
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

    cout << "请输入要删除的倒数第n个节点的n值：";
    int n;
    cin >> n;

    Solution solution;
    ListNode *resultHead = solution.removeNthFromEnd(dummy->next, n);  // 删除链表中倒数第n个节点

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

// 题目保证了n不大于链表节点数, 所以优化下
// ListNode* removeNthFromEnd(ListNode* head, int n) {
//     ListNode *dummyHead = new ListNode(0, head);
//     ListNode *pre = dummyHead;
//     ListNode *cur = dummyHead;

//     while (cur->next != NULL) {
//         cur = cur->next;

//         if (n <= 0) {
//             pre = pre->next;
//         }
//         n--;
//     }

//     pre->next = pre->next->next;
//     return dummyHead->next;
// }

// 改成两次循环的实现形式-更优雅
// ListNode* removeNthFromEnd(ListNode* head, int n) {
//     ListNode *dummyHead = new ListNode(0, head);  // 创建虚拟头节点
//     ListNode *fast = dummyHead;  // fast 初始指向头节点，用于先前进 n 步
//     ListNode *slow = dummyHead;  // slow 初始指向虚拟头节点，最终将指向待删除节点的前一个节点

//     // 先移动 fast 指针 n 步
//     for (int i = 0; i < n; ++i) {
//         fast = fast->next;
//     }

//     // 当 fast 指针到达链表尾部时，slow 指针正好在倒数第 n+1 个节点处
//     while (fast->next != NULL) {
//         fast = fast->next;
//         slow = slow->next;
//     }

//     // 删除倒数第 n 个节点
//     ListNode *toDelete = slow->next;
//     slow->next = toDelete->next;
//     delete toDelete;  // 释放被删除节点的内存

//     ListNode *ans = dummyHead->next;
//     delete dummyHead;  // 释放虚拟头节点的内存
//     return ans;
// }
