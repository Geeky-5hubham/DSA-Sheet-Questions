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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        if(!root)
            return ans;
        vector<int> v;
        bool rev=false;
        // v.push_back(q.front)
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz; i++)
            {
                TreeNode* t=q.front();
                q.pop();
                v.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            if(rev)
                reverse(v.begin(), v.end());
            rev=!rev;
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};