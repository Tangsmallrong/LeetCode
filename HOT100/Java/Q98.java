package hot100;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/**
 * 验证搜索二叉树
 * 递归-中序遍历
 */
public class Q98 {
    private TreeNode pre = null;

    public boolean isValidBST(TreeNode root) {
        if (root == null) {
            return true;
        }

        // 中序遍历
        // 左
        boolean left = isValidBST(root.left);

        // 中
        if (pre != null && pre.val >= root.val) {
            return false;
        }
        pre = root;

        // 右
        boolean right = isValidBST(root.right);

        // 需左右子树均为二叉搜索树
        return left && right;
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
        String[] values = input.split("\\s+");
        int[] arr = new int[values.length];

        for (int i = 0; i < values.length; i++) {
            if ("null".equals(values[i])) {
                arr[i] = -1;
            } else {
                arr[i] = Integer.parseInt(values[i]);
            }
        }

        Q98 solution = new Q98();
        TreeNode root = solution.constructBinaryTree(arr);
        boolean res = solution.isValidBST(root);
        System.out.println(res);
    }
}
