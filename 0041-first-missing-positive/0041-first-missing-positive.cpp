class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        for(auto it:nums){
            if(it > 0)
                s.insert(it);
        }
            
        
        int ans = 1,x = 1;
        for(auto it = s.begin();it != s.end();it++){
            if(*it != x)
                return x;
            x++;
                
        }
        return x;
    }
};