package hot100;

import java.util.Scanner;

/**
 * 排序链表
 */
public class Q148 {
    public ListNode sortList(ListNode head) {
        // 先计算链表的长度
        int len = 0;
        for (ListNode cur = head; cur != null; cur = cur.next) {
            len++;
        }

        // 每次步长翻倍遍历
        for (int step = 1; step < len; step *= 2) {
            // 定义虚拟头结点用于保存合并后的链表
            ListNode dummyHead = new ListNode(0);
            ListNode cur = dummyHead;

            // 计算当前步长下需要合并的次数
            int cnt = (int) Math.ceil(1.0 * len / (2 * step));

            // 进行合并操作
            while (cnt != 0) {
                ListNode p = head;
                ListNode q = head;

                // 找到需要合并的子链表的头节点 p、q
                for (int j = 0; j < step && q != null; j++) {
                    q = q.next;
                }

                // 顺便计算下一组需要合并的子链表的头部
                ListNode next = q;
                for (int j = 0; j < step && next != null; j++) {
                    next = next.next;
                }

                // 合并长度为 step 的两个子链表
                int left = 0;
                int right = 0;
                while (left < step && right < step && p != null && q != null) {
                    if (p.val <= q.val) {
                        cur.next = p;
                        cur = cur.next;
                        p = p.next;
                        left++;
                    } else {
                        cur.next = q;
                        cur = cur.next;
                        q = q.next;
                        right++;
                    }
                }

                // 将剩余的元素接到合并后的链表后面
                while (left < step && p != null) {
                    cur.next = p;
                    cur = cur.next;
                    p = p.next;
                    left++;
                }
                while (right < step && q != null) {
                    cur.next = q;
                    cur = cur.next;
                    q = q.next;
                    right++;
                }

                // 把 head 移动到当前步长下的下一组需要合并的链表的头部
                head = next;
                cnt -= 1;
            }

            // 把 cur->next 置空, 避免链表成环
            cur.next = null;
            // 更新头节点
            head = dummyHead.next;
        }
        return head;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入链表节点数: ");
        int n = scanner.nextInt();

        if (n == 0) {
            System.out.println("排序后的链表: 空");
            return;
        }

        System.out.println("请输入链表节点值: ");
        int val = scanner.nextInt();
        ListNode head = new ListNode(val);
        ListNode current = head;

        for (int i = 1; i < n; ++i) {
            val = scanner.nextInt();
            current.next = new ListNode(val);
            current = current.next;
        }

        Q148 solution = new Q148();
        ListNode sortedHead = solution.sortList(head);

        // 输出排序后的链表
        System.out.print("排序后的链表: ");
        while (sortedHead != null) {
            System.out.print(sortedHead.val + " ");
            sortedHead = sortedHead.next;
        }

        scanner.close();
    }
}
