package link_list;

import java.util.Scanner;

/**
 * 反转链表
 * 迭代/递归实现
 *
 * @author thr
 */
public class Q206 {
    public ListNode reverseList(ListNode head) {
        // 双指针迭代
        ListNode pre = null;
        ListNode cur = head;

        while (cur != null) {
            ListNode temp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = temp;
        }

        return pre;
    }

    public static void main(String[] args) {
        Q206 q206 = new Q206();
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

        // 调用 reverseList 函数进行链表反转
        ListNode resultHead = q206.reverseList(dummy.next);

        // 打印处理后的链表
        System.out.print("反转后的链表: ");
        current = resultHead;
        while (current != null) {
            System.out.print(current.val + " ");
            current = current.next;
        }
        System.out.println();

        scanner.close();
    }

    // 虚拟头节点+头插
//    public ListNode reverseList01(ListNode head) {
//        ListNode dummyHead = new ListNode();
//        ListNode cur = head;
//
//        while (cur != null) {
//            ListNode temp = cur.next;
//            // 头插
//            cur.next = dummyHead.next;
//            dummyHead.next = cur;
//            cur = temp;
//        }
//
//        return dummyHead.next;
//    }
}


