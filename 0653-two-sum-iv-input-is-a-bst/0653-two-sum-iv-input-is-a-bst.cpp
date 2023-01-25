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
    void inorder(TreeNode* root,vector<int> &inOrder){
        if(root == NULL)    return;
        
        inorder(root->left,inOrder);
        inOrder.push_back(root->val);
        inorder(root->right,inOrder);
    }
    
    public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL)    return false;
        vector<int> inOrder;
        
        inorder(root,inOrder);
        
        int n = inOrder.size();
        
        int i = 0,j = n-1;  // TWO POINTER
        
        if(n < 2)   return false;
        
        while( i<j ){
            if(inOrder[i]+inOrder[j] == k)      return true;
            else if(inOrder[i]+inOrder[j] > k)      j--;    // SUM Bada hai
            else    i++;    // SUm chota hai
        }
        
        return false;
    }
};