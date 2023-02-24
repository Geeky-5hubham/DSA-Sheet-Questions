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
private:
    TreeNode* solve(TreeNode* root,int val){
         if(root == NULL){
            TreeNode* ans = new TreeNode(val);
            return ans;
        }
        
        if(root->val > val){
            if(root->left == NULL){
                root->left = new TreeNode(val);
            }
            else
                solve(root->left,val);
        }
        
        if(root->val < val){
            if(root->right == NULL)
                root->right = new TreeNode(val);
            else
                solve(root->right,val);
        }
        return root;
    }
    
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
       return solve(root,val);
    }
};