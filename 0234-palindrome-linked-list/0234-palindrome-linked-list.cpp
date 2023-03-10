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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL)      return true;
        
        vector<int> nums;
        ListNode* temp = head;
        
        while(temp != NULL){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i] != nums[n-i-1])      return false;
        }
        
        return true;
    }
};