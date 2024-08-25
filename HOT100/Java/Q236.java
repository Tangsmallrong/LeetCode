package hot100;

import java.util.LinkedList;
import java.util.Queue;

/**
 * 二叉树的最近公共祖先
 * 递归-后序遍历
 */
public class Q236 {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // 递归终止条件
        if (root == null || root == p || root == q) {
            return root;
        }

        // 后序
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);

        if (left != null && right != null) {
            return root;
        } else if (left == null && right != null) {
            return right;
        } else if (left != null && right == null) {
            return left;
        } else {
            return null;
        }
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

    // 查找二叉树中值为 val 的节点
    private static TreeNode findNode(TreeNode root, int val) {
        if (root == null || root.val == val) {
            return root;
        }

        TreeNode left = findNode(root.left, val);
        if (left != null) return left;

        return findNode(root.right, val);
    }

    public static void main(String[] args) {
        // 输入的二叉树和 p, q 的值
        int[] arr = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4}; // 使用 -1 表示 null
        int pVal = 5;
        int qVal = 1;

        Q236 solution = new Q236();
        TreeNode root = solution.constructBinaryTree(arr);

        // 查找 p 和 q 对应的节点
        TreeNode p = findNode(root, pVal);
        TreeNode q = findNode(root, qVal);

        // 查找最近公共祖先
        TreeNode res = solution.lowestCommonAncestor(root, p, q);

        // 输出结果
        if (res != null) {
            System.out.println(res.val);
        } else {
            System.out.println("not found.");
        }
    }
}
