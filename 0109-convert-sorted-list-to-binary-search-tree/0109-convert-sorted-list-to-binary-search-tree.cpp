/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* inorderToBst(vector<int> &in,int start,int end){
        
        if(start > end)     return NULL;
        
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(in[mid]);
        
        root->left = inorderToBst(in,start,mid-1);
        root->right = inorderToBst(in,mid+1,end);
        
        return root;
        
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)    return NULL;
        
        vector<int> in;
        
        while(head != NULL){
            in.push_back(head->val);
            head = head->next;
        }
        
        return inorderToBst(in,0,in.size()-1);
    }
};