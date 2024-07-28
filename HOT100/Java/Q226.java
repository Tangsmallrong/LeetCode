package hot100;

import java.util.*;

/**
 * 翻转二叉树
 * 层序遍历/前序递归
 */
public class Q226 {
    // 层序遍历
    public TreeNode invertTree(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();

        if (root != null) queue.add(root);
        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size != 0) {
                TreeNode node = queue.poll();  // 出队
                // 交换左右子树(翻转)
                TreeNode temp = node.left;
                node.left = node.right;
                node.right = temp;

                // 若其左右孩子存在则入队
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }

                size--;
            }
        }

        return root;
    }

    // 递归前序遍历
    public TreeNode invertTreeByPreOrder(TreeNode root) {
        if (root == null) return root;

        // 交换左右节点
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;

        // 递归遍历
        invertTreeByPreOrder(root.left);
        invertTreeByPreOrder(root.right);

        return root;
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

    /**
     * 层序遍历翻转后的二叉树
     *
     * @param root 根节点
     * @return 层序遍历结果数组
     */
    public List<Integer> levelOrder(TreeNode root) {
        List<Integer> res = new ArrayList<>();  // 存储遍历结果
        Queue<TreeNode> que = new LinkedList<>();  // 存储每层节点

        if (root != null) {
            que.add(root);
        }
        while (!que.isEmpty()) {
            // 记录当前层节点个数
            int size = que.size();

            // 遍历当前层元素
            while (size != 0) {
                // 队头元素出栈并记录
                TreeNode node = que.poll();
                res.add(node.val);
                // 若其左右孩子存在则入队
                if (node.left != null) {
                    que.add(node.left);
                }
                if (node.right != null) {
                    que.add(node.right);
                }

                size--;
            }
        }

        return res;
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

        Q226 solution = new Q226();
        TreeNode root = solution.constructBinaryTree(arr);
        TreeNode invertRoot = solution.invertTree(root);
        // 层序遍历翻转后的二叉树
        List<Integer> res = solution.levelOrder(invertRoot);

        // 结果输出
        for (Integer num : res) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
