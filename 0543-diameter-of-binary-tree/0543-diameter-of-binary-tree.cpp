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
    int maxHeight(TreeNode* root, int& dia) {

        //base case -> if leaf node, return height 0.
        if(root == NULL) {
            return 0;
        }

        //recursive call for to find max height of each subtree
        int leftHeight = maxHeight(root->left, dia);
        int rightHeight = maxHeight(root -> right, dia);

        //if the sum of new max heights greater than already existing diameter
        dia = max(dia, leftHeight + rightHeight);

        // return max height of the subtree + 1 for the root node
        return 1+ max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        maxHeight(root, dia);
        return dia;
    }
};
