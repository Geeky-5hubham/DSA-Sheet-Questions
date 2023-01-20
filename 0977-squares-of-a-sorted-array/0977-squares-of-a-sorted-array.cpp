class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        priority_queue<int> pq;
        vector<int> ans;
        
        for(auto i:nums)    pq.push(i*i);
        
        for(int i=0;i<nums.size();i++){
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};