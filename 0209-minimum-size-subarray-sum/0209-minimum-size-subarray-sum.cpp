class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        
        int n = nums.size();
        long long int sum = 0;
        int ans = INT_MAX;
        
        while(j < n){
            sum += nums[j];
            
            if(sum >= target){
                ans = min(ans,j-i+1);
                
                while(sum >= target && i < n){
                    sum = sum - nums[i];
                    i++;
                    ans = min(ans,j-i+1);
                }
                
                j++;
                
                
            }
            
            else{
                j++;
            }
        }
        
        if(ans  == INT_MAX)     return 0;
        return ans+1;
    }
};