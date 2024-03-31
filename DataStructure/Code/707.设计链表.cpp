/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

#include <string.h>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

// @lc code=start
class MyLinkedList {
public:
    struct ListNode {  // 链表节点结构体
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* dummyHead;  // 创建虚拟头节点
    int size;  // 链表的当前长度
    
    MyLinkedList() {  // 初始化链表
        dummyHead = new ListNode(0);
        size = 0;
    }
    
    // 获取第 index 个值, 如果 index 值非法则返回 -1
    // index = 0 时返回头节点
    int get(int index) {
        // 注意先判断索引的合法性
        if (index < 0 || index >= size) {
            return -1;
        }

        ListNode* cur = dummyHead->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;   
    }
    
    // 在头部插入节点
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = dummyHead->next;
        dummyHead->next = newNode;
        size++;  // 注意更新链表长度
    }
    
    // 在尾部插入节点
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* cur = dummyHead;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = newNode;
        size++;
    }
    
    // 在 index 的前面插入节点
    void addAtIndex(int index, int val) {
        // 判断索引的合法性
        if (index > size) return;  // 如果 index 大于链表的长度, 则返回空
        if (index < 0) index = 0; // 如果索引为负，则在头部插入

        ListNode* newNode = new ListNode(val);
        ListNode* cur = dummyHead;
        while (index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        size++;
    }
    
    // 删除第 index 个节点
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return; // 索引无效

        ListNode* cur = dummyHead;
        while (index--) {
            cur = cur->next;
        }
        ListNode *toDelete = cur->next;
        cur->next = cur->next->next;
        delete toDelete;
        // delete 命令指示释放了 toDelete 指针原本所指的那部分内存，但 toDelete 仍持有原地址，只是该地址已无效
        // 将 toDelete 设置为 nullptr 可以防止悬挂指针的出现
        // 否则之后的程序如果不⼩⼼使⽤了 toDelete，会指向难以预想的内存空间
        toDelete = nullptr;  // nullptr是C++11引入的新关键字，专门用于表示空指针，提供了更好的类型安全性
        size--;
    }

    // 打印链表
    void printList() {
        ListNode* cur = dummyHead->next; // 从虚拟头节点的下一个节点，即实际的头节点开始遍历
        cout << "当前链表: ";
        while (cur != nullptr) {
            cout << cur->val << " -> ";
            cur = cur->next;
        }
        cout << "NULL" << endl; // 链表末尾打印"NULL"表示链表结束
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

int main() {
    MyLinkedList linkedList;
    int choice, value, index;

    while (true) {
        cout << "\n操作菜单: " << endl;
        cout << "1. 在头部添加节点" << endl;
        cout << "2. 在尾部添加节点" << endl;
        cout << "3. 在指定位置添加节点" << endl;
        cout << "4. 删除指定位置的节点" << endl;
        cout << "5. 获取指定位置的节点值" << endl;
        cout << "6. 打印链表" << endl; // 新增选项
        cout << "0. 退出" << endl;
        cout << "请选择操作：";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "输入要添加的值：";
                cin >> value;
                linkedList.addAtHead(value);
                break;
            case 2:
                cout << "输入要添加的值：";
                cin >> value;
                linkedList.addAtTail(value);
                break;
            case 3:
                cout << "输入位置和值(如: 1 2 表示在位置1添加值2): ";
                cin >> index >> value;
                linkedList.addAtIndex(index, value);
                break;
            case 4:
                cout << "输入要删除节点的位置：";
                cin >> index;
                linkedList.deleteAtIndex(index);
                break;
            case 5:
                cout << "输入要获取节点的位置：";
                cin >> index;
                value = linkedList.get(index);
                if (value != -1) {
                    cout << "节点的值为：" << value << endl;
                } else {
                    cout << "位置不合法或链表为空。" << endl;
                }
                break;
            case 6:
                linkedList.printList(); // 调用打印链表的方法
                break;
            case 0:
                return 0;
            default:
                cout << "无效的选择，请重新输入。" << endl;
                break;
        }
    }

    return 0;
}
