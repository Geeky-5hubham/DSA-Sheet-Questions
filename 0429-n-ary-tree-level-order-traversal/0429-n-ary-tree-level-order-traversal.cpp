/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        
        if(root == NULL){
            return ans;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int n = q.size();
            
            vector<int> temp;
            for(int i=0;i<n;i++){
                Node* front = q.front();
                int data = front->val;
                vector<Node*> children = front->children;
                
                temp.push_back(data);
                q.pop();
                
                for(auto it:children){
                    if(it)
                        q.push(it);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};