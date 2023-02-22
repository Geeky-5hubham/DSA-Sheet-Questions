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
ListNode* reverse(ListNode* head) {
        ListNode* temp = head;
        
        if(head == NULL || head->next == NULL)  return head;
        
        ListNode *p = NULL,*c=temp,*n=temp->next;
        
        while(c != NULL){
            c->next=p;
            p=c;
            c=n;
            if(n != NULL)   n=n->next;
        }
        
        return p;
    }
    
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* x1 = reverse(l1);
        ListNode* x2 = reverse(l2);
        ListNode* l3 = new ListNode(0);
        ListNode* ans = l3;
        
        int carry = 0;
        
        while(x1 != NULL && x2 != NULL){
            int sum = x1->val + x2->val + carry;
            carry = sum/10;
            int digit = sum%10;
            
            l3->next = new ListNode(digit);
            l3 = l3->next;
            x1 = x1->next;
            x2 = x2->next;
        }
        
        while(x1 != NULL){
            int sum = x1->val + carry;
            carry = sum/10;
            int digit = sum%10;
            
            l3->next = new ListNode(digit);
            l3 = l3->next;
            x1 = x1->next;
        }
        
        while(x2 != NULL){
            int sum = x2->val + carry;
            carry = sum/10;
            int digit = sum%10;
            
            l3->next = new ListNode(digit);
            l3 = l3->next;
            x2 = x2->next;
        }
        
        if(carry != 0){
            l3->next = new ListNode(carry);
        }
        return reverse(ans->next);

    }
};