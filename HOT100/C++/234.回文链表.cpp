/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        // 定义快慢指针
        ListNode *slow = head;
        ListNode *fast = head;

        // 先利用快慢指针找到链表中点, 循环结束后慢指针即指向链表中点
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 反转后半部分链表
        ListNode *pre = nullptr;
        ListNode *cur = slow->next;

        while (cur != nullptr) {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }

        // 比较前半部分和反转后的后半部分
        // 从 pre 和 head 开始往后遍历, 遍历到 slow 的过程中都一致则说明是回文
        while (pre != nullptr) {
            if (pre->val != head->val) {
                return false;
            } 

            pre = pre->next;
            head = head->next;
        }

        return true;
    }
};
// @lc code=end

int main() {
    int n;
    cin >> n;

    ListNode* head = nullptr;
    ListNode* cur = nullptr;
    
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (!head) {
            head = new ListNode(val);
            cur = head;
        } else {
            cur->next = new ListNode(val);
            cur = cur->next;
        }
    }

    Solution solution;
    bool result = solution.isPalindrome(head);

    // 输出结果
    cout << (result ? "true" : "false") << endl;

    // 释放链表内存
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}