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
    int findPos(unordered_map<int,int> &m,int x){
       return m[x];
    }
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &index,int inorderStart,int inorderEnd,unordered_map<int,int> &m){
       
        if(index >= preorder.size() || inorderStart > inorderEnd) { // Base Case
            return NULL;
        }  
        
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        
        int pos = findPos(m,element);
        
        root->left = solve(preorder,inorder,index,inorderStart,pos-1,m);
        root->right = solve(preorder,inorder,index,pos+1,inorderEnd,m);
        
        return root;
    }
    
    public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;   //NodeToIndex Mapping
        for(int k=0;k<inorder.size();k++){
            m[inorder[k]] = k;
        }
        int n = preorder.size();
        int index = 0;
        TreeNode* ans = solve(preorder,inorder,index,0,n-1,m);
        
        return ans;
    }
};