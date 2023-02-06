class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> ans;
        set<int> s;
        
        if(nums.size() == 1)    return {nums[0]};
        
        if(nums.size() == 2)
        {
            if(nums[0] == nums[1])  return {nums[0]};
            else    return nums;
            
        }
        int count = 0;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i] == nums[i+1]){
                count++;
                
                if(count+1 > nums.size()/3)     s.insert(nums[i]);
            }
            
            else    count = 0;
        }
       
        for(auto i:s)
        {
            ans.push_back(i);
        }
        return ans;
    }
};