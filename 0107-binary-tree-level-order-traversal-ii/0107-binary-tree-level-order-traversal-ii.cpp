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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       
        vector<vector<int>> ans;
        
        if(root == NULL)    return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            

            int n = q.size();
            vector<int> temp;
            
            for(int i=0;i<n;i++){
                TreeNode* front = q.front();
                temp.push_back(front->val);
                q.pop();
                
                if(front->left)
                q.push(front->left);
            
                if(front->right)
                q.push(front->right);
            }
      
            ans.push_back(temp);
            
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};