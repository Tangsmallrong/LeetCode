package link_list;

import java.util.Scanner;

/**
 * 移除链表元素
 */
public class Q203 {
    public ListNode removeElements(ListNode head, int val) {
        ListNode dummy = new ListNode(0, head);  // 虚拟头节点
        ListNode cur = dummy;

        while (cur.next != null) {
            if (cur.next.val == val) {
                // Java 的内存管理通过垃圾回收机制(GC)自动完成, 所以不需要(也无法)显式地释放对象占用的内存
                cur.next = cur.next.next;
            } else {
                cur = cur.next;
            }
        }

        return dummy.next;
    }

    public static void main(String[] args) {
        Q203 q203 = new Q203();
        Scanner scanner = new Scanner(System.in);

        // 输入链表节点值
        System.out.print("请输入链表节点的值（以空格分隔，回车结束）: ");
        String[] nodeValues = scanner.nextLine().split(" ");
        ListNode dummy = new ListNode(-1); // 创建一个虚拟头节点方便操作
        ListNode current = dummy;

        for (String val : nodeValues) {
            current.next = new ListNode(Integer.parseInt(val));
            current = current.next;
        }

        // 输入要移除的元素值
        System.out.print("请输入要移除的元素值: ");
        int val = scanner.nextInt();

        ListNode resultHead = q203.removeElements(dummy.next, val);

        // 打印处理后的链表
        System.out.print("处理后的链表: ");
        current = resultHead;
        while (current != null) {
            System.out.print(current.val + " ");
            current = current.next;
        }
        System.out.println();

        scanner.close();
    }
}
