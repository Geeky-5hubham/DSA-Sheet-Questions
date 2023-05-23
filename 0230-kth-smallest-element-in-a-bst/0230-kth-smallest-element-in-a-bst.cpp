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

// T.C O(N) S.C O(n)        we can use morris traversal for reducing space complexity to O(1)
class Solution {
    private:
    void inorder(TreeNode* root,int &i,int k,int &ans){
        
        if(root == NULL)    return;
        
        inorder(root->left,i,k,ans);
        i++;
        if(i == k)  {ans = root->val;
            return;
                    }
        inorder(root->right,i,k,ans);
        
    }
    
    
    public:
    int kthSmallest(TreeNode* root, int k) {
        int i = 0,ans = 0;
        inorder(root,i,k,ans);
        
        return ans;
    }
};
