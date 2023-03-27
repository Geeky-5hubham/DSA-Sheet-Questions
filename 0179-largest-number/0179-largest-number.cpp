class Solution {
public:
    static bool check(string &a,string &b){
        return (a+b) >= (b+a);
    }
    
    string largestNumber(vector<int>& nums) {
        int cnt = 0;
        for(auto i:nums){
            if(i == 0)
                cnt++;
        }
        
        if(cnt == nums.size())
            return "0";
        
        string ans = "";
        vector<string> s(nums.size());
        
        for(int i=0;i<nums.size();i++){
            s[i] = to_string(nums[i]);
        }
        sort(s.begin(),s.end(),check);
        
        for(int i=0;i<s.size();i++){
            ans += (s[i]);
        }
        return ans;
    }
};