class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
       /* int n = nums.size();
        
        for(int i = 0;i < nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                nums.erase(nums.begin()+i+1);
                count++;
            }
        }
        return n - count;*/
        set<int> s;
        for(auto i:nums)    s.insert(i);
        
        nums.erase(nums.begin(),nums.end());
        
         for (auto itr = s.begin();
       itr != s.end(); itr++)
        {
            nums.push_back(*itr) ;
        }
        return nums.size();
        
    }
};