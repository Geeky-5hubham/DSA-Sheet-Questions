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
    void flatten(TreeNode* root) {
        if(root == NULL)    return;
        
        TreeNode* curr = root;
        TreeNode* pred = curr->left;  //PRedecessor
        
        
        while(curr != NULL)
        {   TreeNode* pred = curr->left;  //PRedecessor
            if(pred)
            {
                while(pred->right)
                    pred = pred->right;
                    
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
                

            }
            else
            {
                curr = curr->right;
            }
        }
    }
};