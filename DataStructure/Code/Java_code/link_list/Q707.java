package link_list;

import java.util.Scanner;

/**
 * 设计链表
 * 包含链表的基本操作
 *
 * @author thr
 */
public class Q707 {
    ListNode dummyHead;   // 虚拟头节点
    int size;  // 链表当前长度

    public Q707() {  // 初始化
        dummyHead = new ListNode();
        size = 0;
    }

    // 获取元素
    public int get(int index) {
        if (index < 0 || index >= size) {
            return -1;  // 索引不合法, 返回 -1
        }

        ListNode cur = dummyHead.next;
        while (index != 0) {
            cur = cur.next;
            index--;
        }
        return cur.val;
    }

    // 头插
    public void addAtHead(int val) {
        // addAtIndex(0, val);
        ListNode newNode;
        newNode = new ListNode(val);

        newNode.next = dummyHead.next;
        dummyHead.next = newNode;
        size++;
    }

    // 尾插
    public void addAtTail(int val) {
        // addAtIndex(size, val);
        ListNode newNode;
        newNode = new ListNode(val);
        ListNode cur = dummyHead;

        while (cur.next != null) {
            cur = cur.next;
        }

        cur.next = newNode;
        size++;
    }

    // 插入指定位置
    public void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index < 0) index = 0;

        ListNode newNode = new ListNode(val);
        ListNode cur = dummyHead;
        while (index != 0) {
            cur = cur.next;
            index--;
        }

        newNode.next = cur.next;
        cur.next = newNode;
        size++;
    }

    // 删除节点
    public void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;  // 索引不合法
        }

        ListNode cur = dummyHead;
        while (index != 0) {
            cur = cur.next;
            index--;
        }

        // Java 不用手动释放内存
        cur.next = cur.next.next;
        size--;
    }

    // 打印链表
    public void printList() {
        ListNode cur = dummyHead.next;
        System.out.println("当前链表: ");

        while (cur != null) {
            System.out.print(cur.val + "->");
            cur = cur.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        Q707 linkedList = new Q707(); // 使用Q707类创建链表实例
        Scanner scanner = new Scanner(System.in);
        int choice, value, index;

        while (true) {
            System.out.println("\n操作菜单：");
            System.out.println("1. 在头部添加节点");
            System.out.println("2. 在尾部添加节点");
            System.out.println("3. 在指定位置添加节点");
            System.out.println("4. 删除指定位置的节点");
            System.out.println("5. 获取指定位置的节点值");
            System.out.println("6. 打印链表");
            System.out.println("0. 退出");
            System.out.print("请选择操作：");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("输入要添加的值：");
                    value = scanner.nextInt();
                    linkedList.addAtHead(value);
                    break;
                case 2:
                    System.out.print("输入要添加的值：");
                    value = scanner.nextInt();
                    linkedList.addAtTail(value);
                    break;
                case 3:
                    System.out.print("输入位置和值（如：1 2 表示在位置1添加值2）：");
                    index = scanner.nextInt();
                    value = scanner.nextInt();
                    linkedList.addAtIndex(index, value);
                    break;
                case 4:
                    System.out.print("输入要删除节点的位置：");
                    index = scanner.nextInt();
                    linkedList.deleteAtIndex(index);
                    break;
                case 5:
                    System.out.print("输入要获取节点的位置：");
                    index = scanner.nextInt();
                    value = linkedList.get(index);
                    if (value != -1) {
                        System.out.println("节点的值为：" + value);
                    } else {
                        System.out.println("位置不合法或链表为空。");
                    }
                    break;
                case 6:
                    linkedList.printList();
                    break;
                case 0:
                    scanner.close();
                    return; // 使用return来退出循环和程序
                default:
                    System.out.println("无效的选择，请重新输入。");
                    break;
            }
        }
    }
}
