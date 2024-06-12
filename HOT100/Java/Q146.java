package hot100;

import java.util.HashMap;

/**
 * LRU 缓存
 */
public class Q146 {
    public static void main(String[] args) {
        LRUCache lRUCache = new LRUCache(2);
        lRUCache.put(1, 1);  // 缓存是 {1=1}
        lRUCache.put(2, 2);  // 缓存是 {1=1, 2=2}
        System.out.println(lRUCache.get(1));    // 返回 1
        lRUCache.put(3, 3);  // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
        System.out.println(lRUCache.get(2));    // 返回 -1 (未找到)
        lRUCache.put(4, 4);  // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
        System.out.println(lRUCache.get(1));    // 返回 -1 (未找到)
        System.out.println(lRUCache.get(3));    // 返回 3
        System.out.println(lRUCache.get(4));    // 返回 4
    }
}

// 定义双向链表节点
class LRUNode {
    int key;
    int value;
    LRUNode pre;
    LRUNode next;

    public LRUNode() {
        this.key = 0;
        this.value = 0;
        this.pre = null;
        this.next = null;
    }

    public LRUNode(int key, int value) {
        this.key = key;
        this.value = value;
        this.pre = null;
        this.next = null;
    }
}

class LRUCache {
    // 定义双向链表的虚拟头尾节点
    LRUNode head;
    LRUNode tail;

    // 定义哈希表
    HashMap<Integer, LRUNode> map = new HashMap<>();

    // 定义哈希表的容量和已使用大小
    int capacity;
    int size;

    public LRUCache(int capacity) {
        // 初始化哈希表的容量和已使用大小
        this.capacity = capacity;
        this.size = 0;
        // 初始化双向链表的虚拟头尾节点
        this.head = new LRUNode();
        this.tail = new LRUNode();
        // 连接虚拟头尾节点
        head.next = tail;
        tail.pre = head;
    }

    // 根据对应 key 获取 value
    public int get(int key) {
        // 先判断哈希表中是否存在该键
        if (!map.containsKey(key)) {
            // 不存在则返回 -1
            return -1;
        }

        // 先获取 key 对应的节点
        LRUNode node = map.get(key);
        // 将节点从链表删除后放置到链表头
        removeNode(node);
        addNodeToHead(node);
        // 返回节点对应的值
        return node.value;
    }

    // 新增 key-value
    public void put(int key, int value) {
        // 先判断哈希表中是否存在该键
        if (map.containsKey(key)) {
            // 存在则获取到对应的节点后更新 value 值
            LRUNode node = map.get(key);
            node.value = value;
            // 将节点从链表删除后放置到链表头
            removeNode(node);
            addNodeToHead(node);
        } else {
            // 不存在则判断当前哈希表的容量是否还够新增元素
            if (size == capacity) {  // 若不够
                // 删除链表末尾和哈希表中的对应节点
                LRUNode del = tail.pre;
                removeNode(del);
                map.remove(del.key);
                size -= 1;  // 注意减少已使用的容量
            }

            // 在链表头和哈希表中新增节点
            LRUNode node = new LRUNode(key, value);
            addNodeToHead(node);
            map.put(key, node);
            size += 1;  // 增加已使用的容量
        }
    }

    // 辅助函数
    // 从链表中删除节点
    private void removeNode(LRUNode node) {
        node.pre.next = node.next;
        node.next.pre = node.pre;
    }
    // 插入节点到链表的表头
    private void addNodeToHead(LRUNode node) {
        node.pre = head;
        node.next = head.next;
        head.next.pre = node;
        head.next = node;
    }
}
