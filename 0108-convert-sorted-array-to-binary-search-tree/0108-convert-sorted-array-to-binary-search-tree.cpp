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
    TreeNode* helper(vector<int>& nums,int start,int end)
    {
        int mid = start+(end-start)/2;
        
        if(start > end )    return NULL;
        
        TreeNode* newroot = new TreeNode(nums[mid]);
        newroot->left = helper(nums,start,mid-1);
        newroot->right = helper(nums,mid+1,end);
        
        return newroot;
    }
    
    public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        
        TreeNode* ans = helper(nums,0,n-1);
        return ans;
    }
};