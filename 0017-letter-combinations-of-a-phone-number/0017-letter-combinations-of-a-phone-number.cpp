class Solution {
public:
    void f(int ind,string &s,vector<string> &ans,string digits,unordered_map<int,string> &mp){
         if(ind == digits.size()){
             ans.push_back(s);
             return;
         }
        
        string x = mp[digits[ind]-'0'];
             
        for(int i=0;i<x.size();i++){
            s += x[i];
            f(ind+1,s,ans,digits,mp);
            s.pop_back();
         } 
    }
    
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string> mp;
        
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        
        if(digits.size() == 0)
            return {};
        
        vector<string> ans;
        string s = "";
        
        f(0,s,ans,digits,mp);
        return ans;
    }
};