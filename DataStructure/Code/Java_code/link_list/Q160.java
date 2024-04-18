package link_list;

import java.util.Scanner;

/**
 * 相交链表
 * 两链表若相交, 求交点
 */
public class Q160 {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode curA = headA;
        ListNode curB = headB;

        while (curA != curB) {
            curA = curA == null ? headB : curA.next;
            curB = curB == null ? headA : curB.next;
        }

        return curA;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Q160 solution = new Q160();

        // 输入链表A的节点值
        System.out.print("请输入链表A的节点值（以空格分隔，回车结束）: ");
        String[] nodeValuesA = scanner.nextLine().split(" ");
        ListNode dummyA = new ListNode(-1);
        ListNode currentA = dummyA;
        for (String val : nodeValuesA) {
            currentA.next = new ListNode(Integer.parseInt(val));
            currentA = currentA.next;
        }

        // 输入链表B的节点值
        System.out.print("请输入链表B的节点值（以空格分隔，回车结束）: ");
        String[] nodeValuesB = scanner.nextLine().split(" ");
        ListNode dummyB = new ListNode(-1);
        ListNode currentB = dummyB;
        for (String val : nodeValuesB) {
            currentB.next = new ListNode(Integer.parseInt(val));
            currentB = currentB.next;
        }

        // 询问交点信息
        System.out.print("请输入链表A中跳到交叉节点的节点数: ");
        int skipA = scanner.nextInt();
        System.out.print("请输入链表B中跳到交叉节点的节点数: ");
        int skipB = scanner.nextInt();

        // 将链表B连接到链表A的指定交点
        ListNode intersectNodeA = dummyA.next;
        for (int i = 0; i < skipA && intersectNodeA != null; i++) {
            intersectNodeA = intersectNodeA.next;
        }

        ListNode intersectNodeB = dummyB.next;
        for (int i = 0; i < skipB && intersectNodeB != null; i++) {
            intersectNodeB = intersectNodeB.next;
        }

        if (intersectNodeA != null && intersectNodeB != null) {
            intersectNodeB.next = intersectNodeA; // 设置链表B的交点指向链表A的交点
        }

        // 调用函数寻找交点
        ListNode intersection = solution.getIntersectionNode(dummyA.next, dummyB.next);

        // 打印交点信息
        if (intersection != null) {
            System.out.println("交点的节点值为: " + intersection.val);
        } else {
            System.out.println("无交点");
        }

        scanner.close();
    }

//    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
//        ListNode curA = headA;
//        ListNode curB = headB;
//
//        int lenA = 0, lenB = 0;
//        while (curA != null) {
//            curA = curA.next;
//            lenA++;
//        }
//
//        while (curB != null) {
//            curB = curB.next;
//            lenB++;
//        }
//
//        curA = headA;
//        curB = headB;
//
//        int gap = Math.abs(lenA - lenB);
//        if (lenA > lenB) {
//            while (gap != 0) {
//                curA = curA.next;
//                gap--;
//            }
//        } else {
//            while (gap != 0) {
//                curB = curB.next;
//                gap--;
//            }
//        }
//
//        while (curA != curB) {
//            curA = curA.next;
//            curB = curB.next;
//        }
//
//        return curA;
//    }
}
