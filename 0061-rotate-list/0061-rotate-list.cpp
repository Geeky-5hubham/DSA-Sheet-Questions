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
    int length(ListNode* head){
        if(head == NULL)
            return 0;
        
        int ans = 0;
        
        while(head != NULL){
            ans++;
            head = head->next;
        }
        
        return ans;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        
        ListNode* temp = head;
        
        int n = length(head);
        int x = k % n;
        
       while(x--){
            ListNode *curr = temp,*prev = NULL;
           
            while(curr->next != NULL){
                prev = curr;
                curr = curr->next;
            }

            curr->next = temp;
            prev->next = NULL;
            temp = curr;
            
       }
        
        return temp;
    }
};