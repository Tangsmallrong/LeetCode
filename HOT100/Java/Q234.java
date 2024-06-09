package hot100;

import java.util.Scanner;

/**
 * 回文链表
 */
public class Q234 {
    public boolean isPalindrome(ListNode head) {
        // 如果链表为空或长度为 1, 直接返回 true
        if (head == null || head.next == null) return true;

        // 定义快慢指针
        ListNode slow = head;
        ListNode fast = head;

        // 先找到链表的中点, 循环结束后 slow 指针指向的即为链表的中点
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // 对链表的后半部分进行反转, 反转后 pre 指针指向的恰好是链表的最后一个节点
        ListNode pre = null;
        ListNode cur = slow.next;
        while (cur != null) {
            ListNode temp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = temp;
        }

        // 从 pre 和 head 分别开始遍历链表, 判断是否一致, 直到 pre == null
        while (pre != null) {
            if (pre.val != head.val) {
                return false;
            }
            pre = pre.next;
            head = head.next;
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入链表的长度
        System.out.println("请输入链表的长度: ");
        int n = scanner.nextInt();

        // 初始化链表
        ListNode head = null, cur = null;
        System.out.println("请输入链表节点值: ");
        for (int i = 0; i < n; i++) {
            int val = scanner.nextInt();
            if (head == null) {
                head = new ListNode(val);
                cur = head;
            } else {
                cur.next = new ListNode(val);
                cur = cur.next;
            }
        }

        Q234 solution = new Q234();
        boolean result = solution.isPalindrome(head);

        // 输出结果
        System.out.println("链表是否为回文链表: " + result);

        scanner.close();
    }
}
