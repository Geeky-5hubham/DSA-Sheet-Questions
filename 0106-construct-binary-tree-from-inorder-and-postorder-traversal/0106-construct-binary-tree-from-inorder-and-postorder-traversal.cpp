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
    int findPos(unordered_map<int,int> &mp,int x)
    {
        return mp[x];
    }   
    
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int &index,int inorderStart,int                                        inorderEnd,unordered_map<int,int> &mp)
    {
        // BASE CASE
        
        if(index < 0 || inorderStart > inorderEnd)
        {
            return NULL;
        }
        int element = postorder[index--];
        int pos = findPos(mp,element);
        
        TreeNode* root = new TreeNode(element);
        
        root->right = solve(inorder,postorder,index,pos+1,inorderEnd,mp);
        root->left = solve(inorder,postorder,index,inorderStart,pos-1,mp);  // root ka right ka call pehle aayega                                                                                   root ke left se
        
        
        return root;
    }
    public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        
        unordered_map<int,int> mp;  //NodeToIndex in Inorder
        
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        int index = n-1;    //PostOrderIndex
        
        TreeNode* ans = solve(inorder,postorder,index,0,n-1,mp);
        
        return ans;
    }
};