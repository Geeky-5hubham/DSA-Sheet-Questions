class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        int i = 0,j=0;
        
        deque<int> q;
        
        while(j < n){
            while(!q.empty() && q.back() < nums[j])     q.pop_back();
            
            q.push_back(nums[j]);
            
            if(j-i+1 < k)   j++;
            
            else if(j-i+1 == k){
               ans.push_back(q.front());
                
                if(q.front() == nums[i])    // Removing calculation of first element
                    q.pop_front();
                
                i++;
                j++;
            }
        }
        
        return ans;
    }
};