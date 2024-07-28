package hot100;

import java.util.*;

/**
 * 二叉树的层序遍历
 * 广度优先搜索+队列
 */
public class Q102 {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();  // 存储遍历结果
        Queue<TreeNode> que = new LinkedList<>();  // 存储每层节点

        // 当根节点不为空时入队
        if (root != null) {
            que.add(root);
        }

        // 当队列不空时
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

            res.add(cur);
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

        Q102 solution = new Q102();
        TreeNode root = solution.constructBinaryTree(arr);
        List<List<Integer>> res = solution.levelOrder(root);

        // 结果输出
        for (List<Integer> list : res) {
            for (Integer num : list) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
}
