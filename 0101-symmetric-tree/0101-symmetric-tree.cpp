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
    bool isTreeSymmetric(TreeNode* leftRoot, TreeNode* rightRoot){
        if(leftRoot == nullptr && rightRoot == nullptr)
            return true;
        
        if((leftRoot == nullptr && rightRoot != nullptr)  || (leftRoot != nullptr && rightRoot == nullptr))
            return false;
        
        if(leftRoot -> val != rightRoot -> val)
            return false;
        
        return isTreeSymmetric(leftRoot -> left, rightRoot -> right) && isTreeSymmetric(leftRoot -> right,                  rightRoot -> left);
    }
    public:
    bool isSymmetric(TreeNode* root) {
        return isTreeSymmetric(root -> left, root -> right);
    }
};