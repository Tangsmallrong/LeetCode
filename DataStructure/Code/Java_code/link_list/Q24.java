package link_list;

import java.util.Scanner;

/**
 * 两两交换链表中的相邻两个节点
 * 使用虚拟头节点
 */
public class Q24 {
    ListNode swapPairs(ListNode head) {
        ListNode dummyHead = new ListNode(0, head);  // 易错
        ListNode cur = dummyHead;  // 易错

        while (cur.next != null && cur.next.next != null) {
            ListNode temp = cur.next;
            ListNode temp1 = cur.next.next.next;

            cur.next = cur.next.next;
            cur.next.next = temp;
            temp.next = temp1;

            cur = cur.next.next;  // 或者 cur = temp
        }

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

        Q24 solution = new Q24();
        ListNode resultHead = solution.swapPairs(dummy.next);

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
