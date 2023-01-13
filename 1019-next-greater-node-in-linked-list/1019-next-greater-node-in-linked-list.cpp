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
    ListNode* reverse(ListNode* &head){
        if(head == NULL || head->next == NULL)  return head;
        
        ListNode *c = head,*p = NULL,*n=head->next;
        
        while(c != NULL){
            c->next = p;
            p=c;
            c=n;
            if(n != NULL)   n=n->next;
        }
        
        return p;
    }
    
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> s;
        vector<int> ans;
        
        ListNode* temp = reverse(head);
        
        while(temp != NULL){
            int curr = temp->val;
            
            while(!s.empty() && s.top() <=curr){
                s.pop();
            }
            
            if(s.empty())   ans.push_back(0);
            else    ans.push_back(s.top());
            
            s.push(curr);
            temp = temp->next;
        }
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
};