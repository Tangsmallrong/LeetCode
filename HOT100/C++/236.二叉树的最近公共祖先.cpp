/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <string.h>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // 递归-后序遍历
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 递归终止条件
        if (root == nullptr || root == p || root == q) return root;

        // 自底向上遍历
        // 左
        TreeNode* leftNode = lowestCommonAncestor(root->left, p, q);

        // 右
        TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);

        // 中
        // 若两节点均不为空=>pq存在于左右子树中,当前节点即为公共祖先
        if (leftNode && rightNode) {
            return root;
        } else if (leftNode && !rightNode) {
            return leftNode;  // 向上返回(回溯)
        } else if (!leftNode && rightNode) {
            return rightNode;  // 向上返回(回溯)
        } 
        
        return nullptr;
    }
};
// @lc code=end

 // 根据数组构造二叉树
TreeNode* construct_binary_tree(const vector<int>& vec) {
    // 如果输入数组为空，返回空指针
    if (vec.empty()) return nullptr;

    // 使用队列辅助构建二叉树, 按层次遍历的顺序处理节点
    queue<TreeNode*> q;

    // 创建根节点，并将其推入队列
    TreeNode* root = new TreeNode(vec[0]);
    q.push(root);

    // 从第二个元素开始遍历数组
    int index = 1;

    // 当队列不为空时继续循环
    while (!q.empty()) {
        // 从队列中取出当前节点
        TreeNode* node = q.front();
        q.pop();

        // 检查数组中的下一个元素
        // 如果当前索引未超过数组长度且当前值不为-1，创建左子节点
        if (index < vec.size() && vec[index] != -1) {
            node->left = new TreeNode(vec[index]);
            q.push(node->left);  // 将左子节点推入队列
        }
        index++;  // 移动到下一个索引

        // 如果当前索引未超过数组长度且当前值不为-1，创建右子节点
        if (index < vec.size() && vec[index] != -1) {
            node->right = new TreeNode(vec[index]);
            q.push(node->right);  // 将右子节点推入队列
        }
        index++;  // 移动到下一个索引
    }

    // 返回构建好的二叉树的根节点
    return root;
}

// 在二叉树中查找值为val的节点
TreeNode* find_node(TreeNode* root, int val) {
    if (!root) return nullptr;

    // 中
    if (root->val == val) return root;

    // 左
    TreeNode* left = find_node(root->left, val);
    if (left) return left;

    // 右
    return find_node(root->right, val);
}

int main() {
    string input;
    getline(cin, input);  // 读取输入字符串

    istringstream iss(input);  // 将输入字符串转换为输入流
    string val;
    vector<int> vec;
    while (iss >> val) {  // 读取每个值
        if (val == "null") {
            vec.push_back(-1);  // 如果值为"null"，存储为-1
        } else {
            vec.push_back(stoi(val));  // 否则将字符串转换为整数
        }
    }

    TreeNode* root = construct_binary_tree(vec);  // 根据输入构造二叉树

    // 读取 p 和 q 的值
    int p_val, q_val;
    cin >> p_val >> q_val;

    // 在树中查找 p 和 q 节点
    TreeNode* p = find_node(root, p_val);
    TreeNode* q = find_node(root, q_val);

    Solution sol;
    TreeNode* result = sol.lowestCommonAncestor(root, p, q);

    // 输出结果
    if (result) {
        cout << result->val << endl;
    } else {
        cout << "not found" << endl;
    }
    
    return 0;
}