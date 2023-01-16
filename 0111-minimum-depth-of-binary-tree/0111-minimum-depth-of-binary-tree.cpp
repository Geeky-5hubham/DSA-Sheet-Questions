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
    int minDepth(TreeNode* root) {
        if(root == NULL)    return 0;   //Base Case
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        
        if(root->left == NULL && root->right != NULL){
            return right+1;
        }
        
        if(root->left != NULL && root->right == NULL){
            return left+1;
        }
        return min(left,right)+1;
        
    }
};