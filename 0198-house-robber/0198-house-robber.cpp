class Solution {
public:
    int solve(int i,vector<int>& nums,vector<int> &dp){
        if(i == 0)
            return dp[i] = nums[i];
        if(i < 0)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int pick = nums[i] + solve(i-2,nums,dp);
        int notPick = 0 + solve(i-1,nums,dp);
        
        return dp[i] = max(pick,notPick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        
        dp[-1+1] = 0;
        dp[0+1]  =  nums[0];
        
        for(int i=1;i<n;i++){
            int pick = nums[i] + dp[i-2+1];
            int notPick = 0 + dp[i-1+1];
        
            dp[i+1] = max(pick,notPick);
        }
        
        return dp[n];
    }
};