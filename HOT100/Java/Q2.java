package hot100;

import java.util.Scanner;

/**
 * 两数相加
 */
public class Q2 {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // 定义虚拟头节点, 简化操作
        ListNode dummyHead = new ListNode(0);
        ListNode cur = dummyHead;
        int sum = 0;

        // 遍历两个链表
        while (l1 != null || l2 != null || sum != 0) {
            if (l1 != null) {
                sum += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                sum += l2.val;
                l2 = l2.next;
            }

            cur.next = new ListNode(sum % 10);
            cur = cur.next;

            sum /= 10;
        }

        return dummyHead.next;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入第一个链表的长度
        System.out.println("请输入第一个链表的长度: ");
        int n1 = scanner.nextInt();

        // 初始化第一个链表
        ListNode l1 = null, cur = null;
        System.out.println("请输入第一个链表的节点值: ");
        for (int i = 0; i < n1; i++) {
            int val = scanner.nextInt();
            if (l1 == null) {
                l1 = new ListNode(val);
                cur = l1;
            } else {
                cur.next = new ListNode(val);
                cur = cur.next;
            }
        }

        // 输入第二个链表的长度
        System.out.println("请输入第二个链表的长度: ");
        int n2 = scanner.nextInt();

        // 初始化第二个链表
        ListNode l2 = null;
        cur = null;
        System.out.println("请输入第二个链表的节点值: ");
        for (int i = 0; i < n2; i++) {
            int val = scanner.nextInt();
            if (l2 == null) {
                l2 = new ListNode(val);
                cur = l2;
            } else {
                cur.next = new ListNode(val);
                cur = cur.next;
            }
        }

        Q2 solution = new Q2();
        ListNode result = solution.addTwoNumbers(l1, l2);

        // 输出结果
        System.out.println("结果链表: ");
        cur = result;
        while (cur != null) {
            System.out.print(cur.val + " ");
            cur = cur.next;
        }
        System.out.println();

        scanner.close();
    }
}
