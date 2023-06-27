class Solution {
public:
    int check(int mid,vector<int> &nums,int k){
        int c = 0;
        int currSum = 0;
        
        for(int i=0;i<nums.size();i++){
            currSum += nums[i];
            
            if(currSum > mid){
                c++;
                currSum = nums[i];
            }
        }
        
        c++;
        
        return c;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int maxi = 0;
        int end = 0;
        
        for(auto it:nums){
            maxi = max(maxi,it);
            end += it;
        }  
        
        int start = maxi;
        
        long long int mid = start + (end - start) / 2;
        
        while(start <= end){
            if(check(mid,nums,k) > k){
                start = mid+1;
            }
            
            else{
                end = mid-1;
            }
            
            mid = start + (end - start) / 2;
        }
        
        return start;
        
    }
};