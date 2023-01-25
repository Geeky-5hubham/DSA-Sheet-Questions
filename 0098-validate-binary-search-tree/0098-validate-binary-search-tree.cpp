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
    // another approach is to take inorder traversal and store in a vector and check if the vector is sorted or not.if it is sorted then return true else false
    
    bool isBST(TreeNode* root,long int mini,long int maxi){
        if(root == NULL)    return true;
        
        if(root->val > mini && root->val < maxi){
            bool left = isBST(root->left,mini,root->val);
            bool right = isBST(root->right,root->val,maxi);
            
            return left && right;
        }
        else{
            return false;
        }
        
        
        
    }
    
    public:
    bool isValidBST(TreeNode* root) {
        long int mini = LONG_MIN;
        long int maxi = LONG_MAX;
        
        return isBST(root,mini,maxi);
   
    }
};