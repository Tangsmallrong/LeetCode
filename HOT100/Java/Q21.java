package hot100;


import java.util.Scanner;

/**
 * 合并两个有序链表
 */
public class Q21 {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummyHead = new ListNode(0);
        ListNode cur = dummyHead;

        // 遍历两个链表
        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                cur.next = list1;
                list1 = list1.next;
            } else {
                cur.next = list2;
                list2 = list2.next;
            }

            cur = cur.next;
        }

        cur.next = list1 == null ? list2 : list1;

        return dummyHead.next;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入第一个链表的长度和节点值
        System.out.println("请输入第一个链表的长度: ");
        int n1 = scanner.nextInt();
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

        // 输入第二个链表的长度和节点值
        System.out.println("请输入第二个链表的长度: ");
        int n2 = scanner.nextInt();
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

        Q21 solution = new Q21();
        ListNode mergedList = solution.mergeTwoLists(l1, l2);

        // 输出合并后的链表
        System.out.println("合并后的链表为: ");
        cur = mergedList;
        while (cur != null) {
            System.out.print(cur.val + " ");
            cur = cur.next;
        }
        System.out.println();

        scanner.close();
    }
}
