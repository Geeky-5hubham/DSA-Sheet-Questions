class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       
       map<string,vector<string>> mp;
        
        for(auto i : strs)
        {
            string s = i;
            sort(s.begin(),s.end());
            mp[s].push_back(i);
    
        }
        
        vector<vector<string>> ans;
        
        for(auto it:mp){
            ans.push_back(it.second);
        }
        
        return ans;
        
    }
};