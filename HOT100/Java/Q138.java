package hot100;

import java.util.HashMap;
import java.util.Scanner;

/**
 * 随机链表的复制
 */
public class Q138 {
    public Node copyRandomList(Node head) {
        HashMap<Node, Node> map = new HashMap<>();

        // 遍历链表, 将链表节点与拷贝的链表节点的关系记录在哈希表中
        for (Node cur = head; cur != null; cur = cur.next) {
            map.put(cur, new Node(cur.val));
        }

        // 再次遍历链表, 根据原始链表节点之间的next和random指向来设置拷贝链表节点间的关系
        for (Node cur = head; cur != null; cur = cur.next) {
            if (cur.next != null) {
                map.get(cur).next = map.get(cur.next);
            }

            if (cur.random != null) {
                map.get(cur).random = map.get(cur.random);
            }
        }

        return map.get(head);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("请输入链表的长度: ");
        int n = scanner.nextInt();
        scanner.nextLine(); // 消耗换行符

        Node head = null;
        Node cur = null;
        Node[] nodes = new Node[n];
        int[] randomIndices = new int[n];

        System.out.println("请按顺序输入每个节点的值和随机指针的索引（如没有随机指针则输入 -1）:");
        for (int i = 0; i < n; i++) {
            System.out.print("节点 " + (i + 1) + " 的值: ");
            int val = scanner.nextInt();
            System.out.print("节点 " + (i + 1) + " 的随机指针索引: ");
            int randomIndex = scanner.nextInt();
            scanner.nextLine(); // 消耗换行符

            Node newNode = new Node(val);
            nodes[i] = newNode;
            randomIndices[i] = randomIndex;

            if (head == null) {
                head = newNode;
                cur = head;
            } else {
                cur.next = newNode;
                cur = cur.next;
            }
        }

        // 设置随机指针
        for (int i = 0; i < n; i++) {
            if (randomIndices[i] != -1) {
                nodes[i].random = nodes[randomIndices[i]];
            }
        }

        Q138 solution = new Q138();
        Node copiedList = solution.copyRandomList(head);

        // 输出拷贝后的链表
        System.out.print("拷贝后的链表: [");
        cur = copiedList;
        while (cur != null) {
            System.out.print("[" + cur.val + ",");
            if (cur.random != null) {
                for (int i = 0; i < nodes.length; i++) {
                    if (nodes[i].val == cur.random.val) {
                        System.out.print(i);
                        break;
                    }
                }
            } else {
                System.out.print("null");
            }
            System.out.print("]");
            cur = cur.next;
            if (cur != null) {
                System.out.print(",");
            }
        }
        System.out.println("]");

        scanner.close();
    }
}
