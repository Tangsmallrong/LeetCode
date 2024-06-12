/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

#include <string.h>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

// 双向链表
struct Node {
    int key;
    int val;
    Node* pre;
    Node* next;
    
    Node(): key(0), val(0), pre(nullptr), next(nullptr) {}
    Node(int _key, int _val): key(_key), val(_val), pre(nullptr), next(nullptr) {}  
};

// @lc code=start
class LRUCache {
public:
    // 定义双向链表的虚拟头尾节点
    Node* head, *tail;
    
    // 定义存储key和节点映射的哈希表
    unordered_map<int, Node*> map;

    // 记录容量大小和已使用的大小
    int capacity, size;

    // 构造函数, 初始化容量大小和已使用大小(初始为0)
    LRUCache(int _capacity) : capacity(_capacity), size(0) {
        // 初始化虚拟头尾节点
        head = new Node();
        tail = new Node();
        // 连接虚拟头尾节点
        head->next = tail; 
        tail->pre = head;
    }
    
    // 编写辅助函数
    // 从链表中删除节点
    void removeNode(Node* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    // 在链表头插入节点
    void addNodeToHead(Node* node) {
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
    }

    // 获取指定关键字的值
    int get(int key) {
        // 先判断是否存在哈希表中
        if (!map.count(key)) {  // 不存在就返回 -1
            return -1;
        } else {  
            // 存在则获取对应的节点
            Node* node = map[key];
            // 将链表中的该节点删除后重新插入到表头
            removeNode(node);
            addNodeToHead(node);

            // 返回节点对应的值
            return node->val;
        }
    }
    
    // 新增 key-value
    void put(int key, int value) {
        // 先判断是否存在于哈希表中
        if (map.count(key)) {
            // 存在则先获取节点并更新节点的val值
            Node* node = map[key];
            node->val = value;
            // 将链表中的该节点删除后重新插入到表头
            removeNode(node);
            addNodeToHead(node);
        } else {
            // 若不存在于哈希表中, 判断哈希表已使用的大小是否超过容量
            if (size == capacity) {
                // 删除链表末尾的节点, 同时删除哈希表中对应的key-value
                Node* removed = tail->pre;
                removeNode(removed);
                map.erase(removed->key);

                // 使用大小-1
                size--;
            }   

            // 在链表表头和哈希表中插入新的节点
            Node* node = new Node(key, value);
            addNodeToHead(node);
            map[key] = node;
            size++;  // 使用大小+1
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main() {
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    cout << lRUCache.get(1) << endl;    // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lRUCache.get(2) << endl;    // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lRUCache.get(1) << endl;    // 返回 -1 (未找到)
    cout << lRUCache.get(3) << endl;    // 返回 3
    cout << lRUCache.get(4) << endl;    // 返回 4

    return 0;
}