/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include <string.h>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 创建hash表用于存储原链表节点和拷贝后节点间的映射关系
        // 键为原链表节点, 值为拷贝后新创建的节点
        unordered_map<Node*, Node*> map;

        // 遍历原链表, 创建链表中每个节点的拷贝节点, 并在哈希表中存储两者的映射关系
        for (Node *cur = head; cur != nullptr; cur = cur->next) {
            map[cur] = new Node(cur->val);
        }

        // 再次遍历原链表, 根据原链表节点间的关系连接哈希表中创建的拷贝节点
        for (Node *cur = head; cur != nullptr; cur = cur->next) {
            if (cur->next != nullptr) {
                map[cur]->next = map[cur->next];
            }
            if (cur->random != nullptr) {
                map[cur]->random = map[cur->random];
            }
        }
        
        return map[head];
    }
};
// @lc code=end

int main() {
    int n;
    cout << "请输入链表的长度: ";
    cin >> n;

    vector<Node*> nodes(n);
    vector<int> randomIndices(n);

    cout << "请按顺序输入每个节点的值和随机指针的索引（如没有随机指针则输入 -1）:" << endl;
    Node* head = nullptr;
    Node* cur = nullptr;

    for (int i = 0; i < n; ++i) {
        cout << "节点 " << i + 1 << " 的值: ";
        int val;
        cin >> val;
        cout << "节点 " << i + 1 << " 的随机指针索引: ";
        int randomIndex;
        cin >> randomIndex;

        Node* newNode = new Node(val);
        nodes[i] = newNode;
        randomIndices[i] = randomIndex;

        if (head == nullptr) {
            head = newNode;
            cur = head;
        } else {
            cur->next = newNode;
            cur = cur->next;
        }
    }

    // 设置随机指针
    for (int i = 0; i < n; ++i) {
        if (randomIndices[i] != -1) {
            nodes[i]->random = nodes[randomIndices[i]];
        }
    }

    Solution solution;
    Node* copiedList = solution.copyRandomList(head);

    // 输出拷贝后的链表
    cout << "拷贝后的链表: [";
    cur = copiedList;
    while (cur != nullptr) {
        cout << "[" << cur->val << ",";
        if (cur->random != nullptr) {
            for (int i = 0; i < nodes.size(); i++) {
                if (nodes[i]->val == cur->random->val) {
                    cout << i;
                    break;
                }
            }
        } else {
            cout << "null";
        }
        cout << "]";
        cur = cur->next;
        if (cur != nullptr) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    // 释放链表内存
    cur = head;
    while (cur) {
        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }

    cur = copiedList;
    while (cur) {
        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }

    return 0;
}