/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    // 迭代法
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode*> que;

        // 将根节点的左右子节点入队
        que.push(root->left);
        que.push(root->right);

        // 当队列不为空时循环对左右子树的节点成对判断是否符合对称条件
        while (!que.empty()) {
            TreeNode* left = que.front(); que.pop();
            TreeNode* right = que.front(); que.pop();

            // 判断队头两节点
            // 均为空说明当前对应位置上没有节点, 继续检查下一对节点
            if (!left && !right) {
                continue;
            }

            // 一个为空一个不为空或均不空但值不等, 直接返回 false
            if (!left || !right || (left->val != right->val)) {
                return false;
            }

            // 均不空且值相等, 将左右子树外层和内层的节点成对入队
            que.push(left->left);
            que.push(right->right);
            que.push(left->right);
            que.push(right->left);
        }

        return true;
    } 
};
// @lc code=end

// 后序遍历递归法
// bool isSymmetric(TreeNode* root) {
//     return compare(root->left, root->right);
// }
// bool compare(TreeNode* left, TreeNode* right) {
//     if (left && !right) {
//         return false;
//     } else if (!left && right) {
//         return false;
//     } else if (!left && !right) {
//         return true;
//     } else if (left->val != right->val) {
//         return false;
//     }

//     // 对于左右节点均不为空并且 val 值相等的情况
//     // 比较外侧节点
//     bool outside = compare(left->left, right->right);
//     // 比较内侧节点
//     bool inside = compare(left->right, right->left);

//     return outside && inside;
// }

// 构造二叉树
TreeNode* construct_binary_tree(const vector<int>& vec) {
    if (vec.empty()) return nullptr;

    queue<TreeNode*> q;
    TreeNode*root = new TreeNode(vec[0]);
    q.push(root);

    int index = 1;
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (index < vec.size() && vec[index] != -1) {
            node->left = new TreeNode(vec[index]);
            q.push(node->left);
        }
        index++;

        if (index < vec.size() && vec[index] != -1) {
            node->right = new TreeNode(vec[index]);
            q.push(node->right);
        }
        index++;
    }

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
    bool res = sol.isSymmetric(root);  // 判断二叉树是否是对称二叉树
    cout << (res ? "True" : "False") << endl;
    
    return 0;
}
