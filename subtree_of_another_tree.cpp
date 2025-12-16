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

class Solution {
public:
    // checks whether if one tree is a subtree of another
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) {
            return true;
        }

        if (!root) {
            return false;
        }

        if (isSameTree(root, subRoot)) {
            return true;
        }

        // finding a spot where subRoot lies within our original tree (on either left or right branches)
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    // checks if the trees are identical 
    bool isSameTree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) {
            return true;
        }

        if (!root || !subRoot) {
            return false;
        }

        if (root->val != subRoot->val) {
            return false;
        }

        // AND operator since left and right branches of subtree must match 
        return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
    }
};
