/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void LOT(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &par){
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            if(front->left){
                par[front->left] = front;
                q.push(front->left);
            }
            
            if(front->right){
                par[front->right] = front;
                q.push(front->right);
            }
        }
    }
    
   
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root == NULL)    return {};
        
        unordered_map<TreeNode*,TreeNode*> parent_track;
        
        LOT(root,parent_track);
        
        unordered_map<TreeNode*,bool> visited;
        
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;
        
        while(!q.empty()){
            int size = q.size();
            
            if(curr_level++ == k)
                break;
            
            for(int i=0;i<size;i++){
                
                TreeNode* current = q.front();
                q.pop();
                
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left]=true;
                }
                
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right]=true;
                }
                
                if(parent_track[current] && !visited[parent_track[current]]){
                    q.push(parent_track[current]);
                    visited[parent_track[current]]=true;
                }
            }
        }
        vector<int> ans;
        
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            ans.push_back(current->val);
        }
        
        return ans;
    }
};