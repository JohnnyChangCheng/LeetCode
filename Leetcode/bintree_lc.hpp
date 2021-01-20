#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*-------------------------------------------------------------------------------------------------------------------
Problem 100
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
--------------------------------------------------------------------------------------------------------------------*/
class Solution_100 {
public:
    bool preorder(TreeNode* p, TreeNode* q) {
        bool rslt;
        if (p == NULL || q == NULL) {
            if (q == p)
                return true;
            else
                return false;
        }
        if (p->val != q->val) {
            return false;
        }
        rslt = preorder(p->left, q->left);
        if (!rslt)
            return false;
        rslt = preorder(p->right, q->right);
        if (!rslt)
            return false;
        return rslt;

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return preorder(p, q);

    }
};

/*-------------------------------------------------------------------------------------------------------------------
Problem 94
Given the root of a binary tree, return the inorder traversal of its nodes' values.
--------------------------------------------------------------------------------------------------------------------*/
class Solution_94 {
public:
    void inorder(TreeNode* p, vector<int>& array) {
        if (!p)
            return;
        inorder(p->left, array);
        array.push_back(p->val);
        inorder(p->right, array);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

/*-------------------------------------------------------------------------------------------------------------------
Problem 101
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
--------------------------------------------------------------------------------------------------------------------*/
class Solution_102 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> viRet;

        if (root == nullptr)
            return viRet;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> viTmp;

            while (size > 0)
            {
                TreeNode* node = q.front();
                q.pop();

                if (node->left)
                {
                    q.push(node->left);
                }

                if (node->right)
                {
                    q.push(node->right);
                }

                viTmp.push_back(node->val);
                --size;
            }

            viRet.push_back(viTmp);
        }

        return viRet;
    }
};

/*---------------------------------------------------------------------------------------------
Problem 101
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
----------------------------------------------------------------------------------------------*/
class Solution_101 {
public:
    bool isSymmetric(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL || p->val != q->val)
            return false;
        return isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return isSymmetric(root->left, root->right);
    }
};

/*-------------------------------------------------------------------
* Problem 104:
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest 
path from the root node down to the farthest leaf node
-------------------------------------------------------------------*/
class Solution_104 {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

/*------------------------------------------------------------------
Problem 110:
Given a binary tree, determine if it is height - balanced.
For this problem, a height - balanced binary tree is defined as :
------------------------------------------------------------------*/
class Solution_110 {
public:
    int FindHeight(TreeNode* node)
    {
        if (!node) return 0;
        else return max(FindHeight(node->left), FindHeight(node->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (abs(FindHeight(root->left) - FindHeight(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

/*------------------------------------------------------------------------------
Problem 112:
Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
such that adding up all the values along the path equals the given sum.
-------------------------------------------------------------------------------*/
class Solution_112 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        stack<TreeNode*> st{ {root} };
        while (!st.empty()) {
            TreeNode* t = st.top(); st.pop();
            if (!t->left && !t->right) {
                if (t->val == sum) return true;
            }
            if (t->right) {
                t->right->val += t->val;
                st.push(t->right);
            }
            if (t->left) {
                t->left->val += t->val;
                st.push(t->left);
            }
        }
        return false;
    }
};

/*------------------------------------------------------------------------------
Problem 111:
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
-------------------------------------------------------------------------------*/
class Solution_111 {
public:
    int minDepth(TreeNode* root) {
        int l, r;
        if (root == NULL)
            return 0;
        l = minDepth(root->left);
        r = minDepth(root->right);
        if (l == 0)
            return r + 1;
        else if (r == 0)
            return l + 1;
        else
            return min(l, r) + 1;

    }
};