class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        
        if(nums.size() == 0)
            return {};
        
        int start = nums[0];
        int temp = start;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i] == temp+1){
                temp = nums[i];
            }
            
            else{
                string tem;
                if(start == temp){
                    tem = to_string(start);
                }
                
                else{
                    tem = to_string(start) + "->" + to_string(temp);
                }
                
                start = nums[i];
                temp = nums[i];
                
                ans.push_back(tem);
            }
        }
        
        string t;
        if(start == temp){
                    t = to_string(start);
                }
        
                
                else{
                    t = to_string(start) + "->" + to_string(temp);
                }
                
              
                ans.push_back(t);
    
        
        return ans;
        
    }
};