class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        int ans = 0;
        
        unordered_map<char,int> mp;
        mp[s[0]]++;
        
        for(int i=1;i<n;i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]]++;
            }
            
            else{
                ans += 1;
                mp.clear();
                mp[s[i]]++;
            }
        }
        return ans+1;
    }
};