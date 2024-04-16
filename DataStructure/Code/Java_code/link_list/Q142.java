package link_list;

import java.util.Scanner;

/**
 * 环形链表
 * 判断是否存在环形 ==> 快慢指针
 * 判断环形入口 ==> 数学公式
 */
public class Q142 {
    ListNode detectCycle(ListNode head) {
        // 定义快慢指针
        ListNode fast = head;
        ListNode slow = head;

        // 快慢指针按照不同的速度遍历链表
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;

            // 当两个指针相遇的时候说明链表有环
            if (fast == slow) {
                // 根据发现的数学关系寻找环的入口
                ListNode index1 = fast;
                ListNode index2 = head;

                while (index1 != index2) {
                    index1 = index1.next;
                    index2 = index2.next;
                }
                // 从快慢指针相遇的位置和head位置同时出发, 但这两个指针相遇时即为环的入口位置
                return index1;
            }
        }
        return null;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("请输入链表节点的值（以空格分隔，回车结束）: ");
        String[] nodeValues = scanner.nextLine().split(" ");
        ListNode dummy = new ListNode(-1); // 创建一个虚拟头节点方便操作
        ListNode current = dummy;

        // 构建链表
        for (String val : nodeValues) {
            current.next = new ListNode(Integer.parseInt(val));
            current = current.next;
        }

        System.out.print("请输入环的入口位置（0表示第一个节点，负数表示无环）: ");
        int entryIndex = scanner.nextInt();

        // 构建环，如果entryIndex非负则构建环
        if (entryIndex >= 0) {
            ListNode entryNode = dummy.next; // 从头节点开始寻找
            ListNode tailNode = dummy.next; // 也从头节点开始找尾部
            int index = 0; // 索引从头节点开始是0

            /// 定位到环的入口节点
            while (index < entryIndex && entryNode != null) {
                entryNode = entryNode.next;
                index++;
            }

            // 定位到链表尾部
            while (tailNode.next != null) {
                tailNode = tailNode.next;
            }

            // 创建环
            if (entryNode != null) {
                tailNode.next = entryNode;
            }
        }

        Q142 solution = new Q142();
        ListNode cycleEntry = solution.detectCycle(dummy.next);

        if (cycleEntry != null) {
            System.out.println("链表有环，环的入口节点的值为: " + cycleEntry.val);
        } else {
            System.out.println("链表无环");
        }

        scanner.close();
    }
}
