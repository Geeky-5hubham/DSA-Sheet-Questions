class Solution {
public:
    // Ans ya to product of 3 max no hoga ya 2 min(-ve) and max1 hoga
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        
        int n = nums.size();
        
        for(int i = 0;i < n;i++){
            int num = nums[i];
            
            if(num > max1){
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            
            else if(num > max2){
                max3 = max2;
                max2 = num;    
            }
            
            else if(num > max3){
                max3 = num;
            }
        }
        
         for(int i = 0;i < n;i++){
            int num = nums[i];
            
            if(num < min1){
                min2 = min1;
                min1 = num;
            }
            
            else if(num < min2){
                min2 = num;    
            }
            
        }
        
        return max(max1*max2*max3,min2*min1*max1);
        
        
    }
};