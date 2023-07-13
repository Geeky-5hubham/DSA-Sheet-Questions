class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        set<int>s;
        
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        
        vector<int>unique;
        
        for(auto item:s){
            unique.push_back(item);
        }

        int ans = INT_MAX;
        
        for(int i=0;i<unique.size();i++){
            
            int start = unique[i];
            int last = start + n-1;
            
            auto upper=upper_bound(unique.begin(),unique.end(),last);
            
            int len = upper - (unique.begin()+i);
            ans = min(ans,n-(len));
            
        }
       return ans;
    }
};
