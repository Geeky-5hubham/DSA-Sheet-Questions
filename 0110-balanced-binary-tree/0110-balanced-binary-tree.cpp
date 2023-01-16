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
        pair<bool,int> isBalancedFast(TreeNode* root){
            if(root == NULL){
                pair<bool,int> p = make_pair(true,0);
                return p;
            }
            
            pair<bool,int> leftAns = isBalancedFast(root->left);
            pair<bool,int> rightAns = isBalancedFast(root->right);
            
            bool isLeftBalanced = leftAns.first;
            bool isRightBalanced = rightAns.first;
            bool diff = abs(leftAns.second - rightAns.second) <= 1;
            
            pair<bool,int> ans;
            ans.second = max(leftAns.second,rightAns.second)+1;
            
            if(isLeftBalanced && isRightBalanced && diff){
                ans.first = true;
            }
            else{
                ans.first = false;
            }
            return ans;      
        }
    public:
        bool isBalanced(TreeNode* root) {
            return isBalancedFast(root).first;
        }
};