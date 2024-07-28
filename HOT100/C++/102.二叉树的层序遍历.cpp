/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    // 队列实现广度优先搜索
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 存储遍历结果的二维数组
        vector<vector<int>> res;
        // 存储每层节点的队列
        queue<TreeNode*> que;

        // 若根节点不为空, 则将其入队
        if (root != nullptr) que.push(root);

        // 当队列非空时循环遍历二叉树
        while (!que.empty()) {
            // 记录当前层的节点数量
            int size = que.size();

            // 存储当前层的遍历结果
            vector<int> vec;

            // 遍历当前层的节点
            while (size--) {
                // 将队头元素出队并记录
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);

                // 将当前节点的左右孩子(如果存在)入队
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }

            // 记录当前层的遍历结果
            res.push_back(vec);
        }

        return res;
    }
};
// @lc code=end

// 根据数组构造二叉树
// 利用队列逐层构建二叉树，通过依次读取数组中的值，构建每个节点及其左右子节点
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
    vector<vector<int>> result = sol.levelOrder(root);  // 层序遍历二叉树

    // 输出遍历结果
    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}

