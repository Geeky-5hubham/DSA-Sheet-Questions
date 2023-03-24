class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans(n);
        
        vector<int> pre(n),suff(n);
        int prod1 = 1,prod2 = 1;
        for(int i=0;i<n;i++){
            prod1 = prod1*nums[i];
            prod2 = prod2*nums[n-i-1];
            pre[i] = prod1;
            suff[n-i-1] = prod2;
        }
        
        ans[0] = suff[1];
        ans[n-1] = pre[n-1-1];
        
        for(int i=1;i<n-1;i++){
            ans[i] = pre[i-1]*suff[i+1];
        }
        
        return ans;
        
    }
};