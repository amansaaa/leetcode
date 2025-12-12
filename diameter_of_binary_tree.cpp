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
    int res = 0;

    int height(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        res = max(res, (leftHeight + rightHeight)); // updates the best diameter (biggest diameter)
        return 1 + max(leftHeight, rightHeight);    // returns the height
    }

    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        height(root);
        return res;
        
    }
};
