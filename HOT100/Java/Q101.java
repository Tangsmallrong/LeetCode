package hot100;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/**
 * 对称二叉树
 * 递归/迭代
 */
public class Q101 {
    // 迭代法
    public boolean isSymmetric(TreeNode root) {
        if (root == null) return true;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root.left);
        queue.add(root.right);

        while (!queue.isEmpty()) {
            TreeNode leftNode = queue.poll();
            TreeNode rightNode = queue.poll();

            if (leftNode == null && rightNode == null) {
                continue;
            } else if (leftNode == null || rightNode == null || (leftNode.val != rightNode.val)) {
                return false;
            }

            queue.add(leftNode.left);
            queue.add(rightNode.right);
            queue.add(leftNode.right);
            queue.add(rightNode.left);
        }

        return true;
    }

    public boolean isSymmetricByRecursion(TreeNode root) {
        // 递归法
        return compare(root.left, root.right);
    }

    // 递归法
    private boolean compare(TreeNode leftNode, TreeNode rightNode) {
        // 递归终止条件
        if (leftNode == null && rightNode == null) {
            return true;
        } else if (leftNode == null || rightNode == null || (leftNode.val != rightNode.val)) {
            return false;
        }

        boolean outside = compare(leftNode.left, rightNode.right);
        boolean inside = compare(leftNode.right, rightNode.left);

        return outside && inside;
    }

    // 构造二叉树
    private TreeNode constructBinaryTree(final int[] arr) {
        if (arr.length == 0) return null;

        Queue<TreeNode> queue = new LinkedList<>();
        TreeNode root = new TreeNode(arr[0]);
        queue.add(root);
        int index = 1;

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();

            if (index < arr.length && arr[index] != -1) {
                node.left = new TreeNode(arr[index]);
                queue.add(node.left);
            }
            index++;

            if (index < arr.length && arr[index] != -1) {
                node.right = new TreeNode(arr[index]);
                queue.add(node.right);
            }
            index++;
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

        Q101 solution = new Q101();
        TreeNode root = solution.constructBinaryTree(arr);
        boolean res = solution.isSymmetricByRecursion(root);

        // 结果输出
        System.out.println(res);
    }
}
