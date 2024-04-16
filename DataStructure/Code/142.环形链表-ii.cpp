/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;  // 定义快指针，初始指向链表头部
        ListNode *slow = head;  // 定义慢指针，初始也指向链表头部

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;  // 快指针移动两步
            slow = slow->next;  // 慢指针移动一步

            if (fast == slow) {  // 当快指针追上慢指针时，说明链表存在环
                ListNode *index1 = fast;  // 从快慢指针相遇点开始一个新的指针
                ListNode *index2 = head;  // 从头节点开始另一个新的指针

                while (index1 != index2) {  // 移动两个指针，直到它们在环的入口节点相遇
                    index1 = index1->next;
                    index2 = index2->next;
                }

                return index1;  // 返回环的起始节点
            }
        }
        return NULL;  // 如果快指针遍历完链表都没有和慢指针相遇，说明链表无环
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
    vector<ListNode*> nodeVec;  // 保存所有节点，以便构造环

    // 构建链表
    while (ss >> number) {
        current->next = new ListNode(number);
        current = current->next;
        nodeVec.push_back(current); // 将当前节点加入到数组中
    }

    int cycleIndex; // 环的入口位置
    cout << "请输入环的入口位置（0表示第一个节点，负数表示无环）: ";
    cin >> cycleIndex;

    if (cycleIndex >= 0 && cycleIndex < nodeVec.size()) {
        current->next = nodeVec[cycleIndex];  // 构造环
    }

    Solution solution;
    ListNode *cycleEntry = solution.detectCycle(dummy->next);

    if (cycleEntry != nullptr) {
        cout << "链表有环，环的入口节点的值为: " << cycleEntry->val << endl;
    } else {
        cout << "链表无环" << endl;
    }

    // 释放链表内存
    current = dummy->next;
    vector<ListNode*> visited;  // 存储访问过的节点，避免重复释放
    while (current != nullptr) {
        if (find(visited.begin(), visited.end(), current) != visited.end()) {
            // 如果节点已经访问过，终止循环
            break;
        }
        visited.push_back(current); // 标记当前节点为已访问
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    delete dummy;  // 释放虚拟头节点的内存

    return 0;
}
