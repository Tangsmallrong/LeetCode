package hot100;

import java.util.*;

/**
 * 二叉树的右视图
 * 层序遍历
 */
public class Q199 {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();  // 存储遍历结果
        Queue<TreeNode> que = new LinkedList<>();  // 存储每层节点

        if (root != null) {
            que.add(root);
        }
        while (!que.isEmpty()) {
            // 记录当前层节点个数
            int size = que.size();

            // 存储当前层遍历结果
            List<Integer> cur = new ArrayList<>();

            // 遍历当前层元素
            while (size != 0) {
                // 队头元素出栈并记录
                TreeNode node = que.poll();
                cur.add(node.val);

                // 若其左右孩子存在则入队
                if (node.left != null) {
                    que.add(node.left);
                }
                if (node.right != null) {
                    que.add(node.right);
                }

                size--;
            }

            // 将当前层的最后一个节点存入结果数组
            res.add(cur.get(cur.size() - 1));
        }

        return res;
    }

    /**
     * 构建二叉树
     *
     * @param arr 树中元素数值的数组表示
     * @return 构建的二叉树的根节点
     */
    public TreeNode constructBinaryTree(final int[] arr) {
        if (arr.length == 0) return null;

        Queue<TreeNode> que = new LinkedList<>();
        TreeNode root = new TreeNode(arr[0]);
        que.add(root);

        int idx = 1;
        while (!que.isEmpty()) {
            TreeNode node = que.poll();

            if (idx < arr.length && arr[idx] != -1) {
                node.left = new TreeNode(arr[idx]);
                que.add(node.left);
            }
            idx++;

            if (idx < arr.length && arr[idx] != -1) {
                node.right = new TreeNode(arr[idx]);
                que.add(node.right);
            }
            idx++;
        }

        return root;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        String[] values = input.split("\\s+");  // 将输入字符串按照一个或多个空白字符进行拆分
        int[] arr = new int[values.length];

        for (int i = 0; i < values.length; i++) {
            if ("null".equals(values[i])) {
                arr[i] = -1;
            } else {
                arr[i] = Integer.parseInt(values[i]);
            }
        }

        Q199 solution = new Q199();
        TreeNode root = solution.constructBinaryTree(arr);
        List<Integer> res = solution.rightSideView(root);

        // 结果输出
        for (Integer num : res) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
