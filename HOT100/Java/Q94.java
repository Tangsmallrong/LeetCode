package hot100;

import java.util.*;

/**
 * 二叉树的中序遍历
 * 深度优先搜索+递归/栈
 */
public class Q94 {
    // 迭代法
    public List<Integer> inorderTraversal(TreeNode root) {
        Deque<TreeNode> stk = new LinkedList<>();  // 用栈模拟递归
        List<Integer> res = new ArrayList<>();  // 存放遍历结果
        TreeNode cur = root;  // 定义指针辅助遍历

        while (cur != null || !stk.isEmpty()) {
            // 遍历左子树, 入栈
            while (cur != null) {
                stk.push(cur);
                cur = cur.left;
            }

            // 当前指针指向节点为空, 将栈顶元素出栈并存入结果数组
            cur = stk.pop();
            res.add(cur.val);

            // 遍历右子树
            cur = cur.right;
        }

        return res;
    }

    // 递归写法
    public List<Integer> inorderTraversalByRecursion(TreeNode root) {
        // 定义结果数组, 存储遍历结果
        List<Integer> res = new ArrayList<>();
        // 调用函数实现遍历, 传入根节点和结果数组
        traversal(root, res);
        return res;
    }
    // 递归实现中序遍历
    private void traversal(TreeNode root, List<Integer> res) {
        // 递归终止条件
        if (root == null) {
            return;
        }

        // 左
        traversal(root.left, res);

        // 中
        res.add(root.val);

        // 右
        traversal(root.right, res);
    }

    /**
     * 构建二叉树
     * @param arr 树中元素数值的数组表示
     * @return 构建的二叉树的根节点
     */
    public TreeNode constructBinaryTree(final int[] arr) {
        if (arr.length == 0) return null;

        // 利用队列辅助构建二叉树
        Queue<TreeNode> queue = new LinkedList<>();
        // 先将第一个元素作为根节点并入队
        TreeNode root = new TreeNode(arr[0]);
        queue.add(root);

        // 从第二个节点开始遍历
        int idx = 1;

        // 当队列不为空时
        while (!queue.isEmpty()) {
            // 先将当前队头元素出队
            TreeNode node = queue.poll();

            // 继续判断数组后续元素, 查找出队节点的左右子节点
            if (idx < arr.length && arr[idx] != -1) {
                node.left = new TreeNode(arr[idx]);
                // 将左子节点入队
                queue.add(node.left);
            }
            idx++;

            if (idx < arr.length && arr[idx] != -1) {
                node.right = new TreeNode(arr[idx]);
                // 将右子节点入队
                queue.add(node.right);
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

        Q94 solution = new Q94();
        TreeNode root = solution.constructBinaryTree(arr);
        List<Integer> res = solution.inorderTraversal(root);

        // 结果输出
        for (Integer num : res) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
