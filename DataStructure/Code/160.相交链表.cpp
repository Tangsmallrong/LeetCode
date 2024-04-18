/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;

        // 分别计算两个链表的长度
        int lenA = 0, lenB = 0;
        while (curA != NULL) {
            curA = curA->next;
            lenA++;
        }

        while (curB != NULL) {
            curB = curB->next;
            lenB++;
        }

        // 重置指针到各自链表的头部
        curA = headA;
        curB = headB;

        // 根据长度差调整长链表的指针
        int gap = abs(lenA - lenB);
        if (lenA > lenB) {
            while (gap--) curA = curA->next;
        } else {
            while (gap--) curB = curB->next;
        }

        // 同步遍历两个链表，直到找到交点或者同时到达末尾(都为NULL)
        while (curA != curB) {
            curA = curA->next;
            curB = curB->next;
        }

        return curA;  // 可能返回NULL，表示无交点，或返回交点
    }
};
// @lc code=end

ListNode* createList(const vector<int>& nums) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (int num : nums) {
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    return dummy.next;
}

int main() {
    // 获取链表A的节点值
    cout << "请输入链表A的节点值（以空格分隔，回车结束）: ";
    string lineA;
    getline(cin, lineA);
    stringstream ssA(lineA);
    int number;
    vector<int> valuesA;
    while (ssA >> number) {
        valuesA.push_back(number);
    }

    // 获取链表B的节点值
    cout << "请输入链表B的节点值（以空格分隔，回车结束）: ";
    string lineB;
    getline(cin, lineB);
    stringstream ssB(lineB);
    vector<int> valuesB;
    while (ssB >> number) {
        valuesB.push_back(number);
    }

    // 创建链表
    ListNode* listA = createList(valuesA);
    ListNode* listB = createList(valuesB);

    // 询问交点信息
    int skipA, skipB;
    cout << "请输入链表A中跳到交叉节点的节点数: ";
    cin >> skipA;
    cout << "请输入链表B中跳到交叉节点的节点数: ";
    cin >> skipB;

    // 链接两个链表形成交点
    ListNode *curA = listA, *curB = listB;
    ListNode *tailA = nullptr, *tailB = nullptr;
    int indexA = 0, indexB = 0;

    while (curA != nullptr && indexA < skipA) {
        tailA = curA;
        curA = curA->next;
        indexA++;
    }

    while (curB != nullptr && indexB < skipB) {
        tailB = curB;
        curB = curB->next;
        indexB++;
    }

    if (curA && curB) {
        tailB->next = curA;  // Assume curA is the intersection start
    }

    // 使用函数找到交点
    Solution solution;
    ListNode *intersection = solution.getIntersectionNode(listA, listB);

    if (intersection != nullptr) {
        cout << "交点的节点值为: " << intersection->val << endl;
    } else {
        cout << "无交点" << endl;
    }

    // 清理内存
    ListNode* next;
    curA = listA;
    while (curA != nullptr) {
        next = curA->next;
        if (curA == tailB->next) break;  // 到达交点开始的共享部分，停止删除
        delete curA;
        curA = next;
    }

    curB = listB;
    while (curB != tailB->next) {  // 删除B链表中非共享部分的节点
        next = curB->next;
        delete curB;
        curB = next;
    }

    return 0;
}

// 更优雅的解法
// ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//     ListNode *curA = headA;
//     ListNode *curB = headB;

//     while (curA != curB) {
//         curA = curA == NULL ? headB : curA->next;
//         curB = curB == NULL ? headA : curB->next;
//     }

//     return curA;
// }