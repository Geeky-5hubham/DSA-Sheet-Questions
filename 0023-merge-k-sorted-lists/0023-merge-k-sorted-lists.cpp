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
class compare{
    public:
    bool operator()(ListNode*a,ListNode*b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int K = lists.size();
        
        if(K == 0)
            return NULL;
        
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        
        for(int i=0;i<K;i++){
            if(lists[i] != NULL)
                pq.push(lists[i]);  
        }
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
       
        while(pq.size() > 0){
            ListNode* top = pq.top();
            pq.pop();
            
            if(top-> next != NULL)
                pq.push(top->next);
            
            if(head == NULL)    // Answer LL is empty;
            {
                head = top;
                tail = top;
            }
            
            else        // Insert At end
            {
                tail->next = top;
                tail = top;
            }
          
         }
        
        return head;
        
    }
};