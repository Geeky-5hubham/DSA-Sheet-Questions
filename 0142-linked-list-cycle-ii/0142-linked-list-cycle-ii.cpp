/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) break;
        }
        
        // No cycle exist
        if(fast == NULL || fast->next == NULL)
            return NULL;
        
        ListNode* temp = head;
        
        while(temp != slow){
            temp = temp->next;
            slow = slow->next;
        }
        
        return slow;
    }
};