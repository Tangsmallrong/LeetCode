package hot100;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/**
 * 二叉树的直径
 * 递归-后序遍历
 */
public class Q543 {
    private int res = 0;

    public int diameterOfBinaryTree(TreeNode root) {
        // 递归
        if (root == null) return 0;
        depth(root);
        return res;
    }

    private int depth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int leftHeight = depth(root.left);
        int rightHeight = depth(root.right);

        res = Math.max(res, leftHeight + rightHeight);
        return Math.max(leftHeight, rightHeight) + 1;
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

        Q543 solution = new Q543();
        TreeNode root = solution.constructBinaryTree(arr);
        int res = solution.diameterOfBinaryTree(root);
        System.out.println(res);
    }
}
