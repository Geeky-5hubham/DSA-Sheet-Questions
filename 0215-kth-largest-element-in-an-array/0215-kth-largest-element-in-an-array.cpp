class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        
        int ans;
        
        for(int i=1;i<k;i++){
            pq.pop();
        }
        
        ans = pq.top();
        
        return ans;
 
        
        /*int res[k];
        
        int j=0;
        
        while(k--){
            
            int maxi=INT_MIN;
            
            for(int i = 0 ; i<nums.size();i++){
                if (maxi<nums[i]){
                    maxi=nums[i];
                }
            }
            
            res[j]=maxi;
            
            j++;
             
            for(int i =0 ; i < nums.size() ; i++){
               
                if (nums[i] == res[j-1]){
                    nums[i]=INT_MIN;
                    break;
                }
            }
        }
        return res[j-1];
        */
        
        
    }
};