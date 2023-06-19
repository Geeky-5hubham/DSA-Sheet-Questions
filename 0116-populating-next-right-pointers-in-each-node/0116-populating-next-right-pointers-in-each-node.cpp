/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    vector<vector<Node*>> LOT(Node* root){
        vector<vector<Node*>> res;
        
        if(root == NULL)
            return res;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            
            vector<Node*> temp;
            
            for(int i=0;i<n;i++){
                Node* front = q.front();
                q.pop();
                
                temp.push_back(front);
                
                if(front->left != NULL)     q.push(front->left);
                if(front->right != NULL)    q.push(front->right);
            }
            
            res.push_back(temp);
        }
        return res;
    }
    
    Node* connect(Node* root) {
        vector<vector<Node*>> v = LOT(root);
        
        for(int i=0;i<v.size();i++){
            vector<Node*> temp = v[i];
            
            for(int j=0;j<temp.size()-1;j++){
                temp[j]->next = temp[j+1];    
            }
            temp[temp.size()-1]->next = NULL;
        }
        
        return root;
    }
};