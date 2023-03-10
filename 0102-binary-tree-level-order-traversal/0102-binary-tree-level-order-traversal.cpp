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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelorder;
        // return empty vector if no tree exists.
         if(root ==NULL) return levelorder;
         queue<TreeNode*> q; // queue for storing nodes level by level
         q.push(root);
         while(!q.empty()){
             int size=q.size(); //get size of particular level (no. of elements in tree at level.)
             vector<int> level;
            // Traverse the level push left and right if exixts in node.
             for(int i=0;i<size;i++){
                 level.push_back(q.front()->val);
                 if(q.front()->left) q.push(q.front()->left);
                 if(q.front()->right) q.push(q.front()->right);
                 q.pop();
             }
            // push level vector to the resultant vector.
             levelorder.push_back(level);
         }
         return levelorder;
    }
};