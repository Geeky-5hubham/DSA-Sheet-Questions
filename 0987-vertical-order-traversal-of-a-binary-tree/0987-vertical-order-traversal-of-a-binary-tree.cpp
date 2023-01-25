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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       /* vector<vector<int>> ans;
        
        map<int,map<int,vector<int> > > Nodes;    // First int represent horizontal distance
        
        queue<pair < TreeNode*,pair<int,int> > >q;      // queue having nodes Horizontal distance as first part of pair and level as second part of pair
        int hd = 0 ;    // HORIszontal distnce is 0 in starting as well as level
        int lv = 0;
        
        q.push(make_pair(root,make_pair(hd,lv)));
        
        while(!q.empty()){
            pair<TreeNode*,pair<int,int> > front = q.front();
            q.pop();
            
            TreeNode* frontNode = front.first;
            hd = front.second.first;
            lv = front.second.second;
            
            Nodes[hd][lv].push_back(frontNode->val);
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,make_pair(hd-1,lv+1)));
            }
            
            if(frontNode->right){
                q.push(make_pair(frontNode->right,make_pair(hd+1,lv+1)));
            }
        }
        vector<int> ans1;
               for (auto i : Nodes){
                   vector<int> temp;
                   for(auto j:i.second){
                       for(auto k:j.second)
                           temp.push_back(k);
                   }
                  // sort(temp.begin(),temp.end());
                   ans.push_back(temp);
               }
               
               
               return ans;
               */
        
                queue<pair<TreeNode* , pair<int, int>>> fuck; // node , <vertical, horizontal>
        map<int, map<int, multiset<int>>> deep ; // <vertical , <horizontal, multiset<nodes>>

        vector<vector<int>> ans ; if(root == NULL){return ans ;}
        fuck.push({root , {0 , 0}}) ;

        while(!fuck.empty()){
            auto sax  = fuck.front() ; int size = fuck.size() ; fuck.pop() ;
            TreeNode* node = sax.first ;
            int vertical = sax.second.first , horizontal = sax.second.second ;

            // ab isko deep daal do
            deep[vertical][horizontal].insert(node -> val) ;

            // ab baari hain ki left aur right daal do
            if(node -> left != NULL){
                fuck.push({node -> left , {vertical-1 , horizontal + 1}}) ;
            }
            if(node -> right){
                fuck.push({node -> right, {vertical+1 , horizontal +1}}) ;
            }
        }

        for (auto &&cum : deep){
            vector<int> hole ;
            for (auto &&i : cum.second){
                hole.insert(hole.end() , i.second.begin() , i.second.end()) ;
            }
            ans.push_back(hole) ;
        }
        return ans ;

        
    }
};