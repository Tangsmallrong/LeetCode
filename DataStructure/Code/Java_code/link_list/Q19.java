package link_list;

import java.util.Scanner;

/**
 * 删除链表倒数第N个节点
 * 快慢指针
 */
public class Q19 {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummyHead = new ListNode(0, head);
        ListNode fast = dummyHead;
        ListNode slow = dummyHead;

        for (int i = 0; i < n; i++) {
            fast = fast.next;
        }

        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }

        slow.next = slow.next.next;

        return dummyHead.next;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("请输入链表节点的值（以空格分隔，回车结束）: ");
        String[] nodeValues = scanner.nextLine().split(" ");
        ListNode dummy = new ListNode(-1); // 创建一个虚拟头节点方便操作
        ListNode current = dummy;

        for (String val : nodeValues) {
            current.next = new ListNode(Integer.parseInt(val));
            current = current.next;
        }

        System.out.print("请输入要删除的倒数第n个节点的n值: ");
        int n = scanner.nextInt();

        Q19 solution = new Q19();
        ListNode resultHead = solution.removeNthFromEnd(dummy.next, n);

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
