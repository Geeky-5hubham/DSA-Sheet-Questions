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

class info{
    public:
    int mini;
    int maxi;
    int sum ;
    bool isBst;  
};



class Solution {
    private:
    info solve(TreeNode* root,int &ans){
        if(root == NULL)    return{INT_MAX,INT_MIN,0,true};
        
      //  if(root->left == NULL && root->right == NULL)
        //    return {root->val,root->val,root->val,true};
        
        info left = solve(root->left,ans);
        info right = solve(root->right,ans);
        
        info currNode;
        
        currNode.maxi = max(root->val,right.maxi);
        currNode.mini = min(root->val,left.mini);
        
        
        if(left.isBst && right.isBst && root->val > left.maxi && root->val < right.mini){
            currNode.isBst = true;
            currNode.sum = left.sum + right.sum + root->val;
        }
        else {
        currNode.isBst  = false;
        }
        
        
        if(currNode.isBst)
            ans = max(ans,currNode.sum);
        
        return currNode;
    }
    
    public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        info t = solve(root,ans);
        return ans;
    }
    

};