/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        // 递归
        if (root == nullptr) return 0;
        depth(root);
        return res;
    }

    int depth(TreeNode* node) {
        // 递归结束条件, 如果当前节点为空, 返回深度为0
        if (node == nullptr) {
            return 0;
        }

        // 递归计算左子树的最大深度
        int leftHeight = depth(node->left);

        // 递归计算右子树的最大深度
        int rightHeight = depth(node->right);

        // 更新全局变量 res, 比较当前最大直径与当前节点的左右子树深度之和
        // 确保 res 保存的是整个二叉树中的最大直径
        res = max(res, leftHeight + rightHeight);

        // 返回当前节点的最大深度, 即左右子树深度中的较大者再加1（包含当前节点自身）
        return max(leftHeight, rightHeight) + 1;
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

    Solution sol;
    int result = sol.diameterOfBinaryTree(root);  // 计算直径

    // 输出遍历结果
    cout << result << endl;
    
    return 0;
}

