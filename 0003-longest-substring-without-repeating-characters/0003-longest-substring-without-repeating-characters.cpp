class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        
        int i=0;
        int j=0;
        
        int n = s.size();
        
        string temp = "";
        int ans = 0;
        
        while(j < n){
            
            if(mp.find(s[j]) != mp.end()){
                int previ = i;
                
                i = mp[s[j]] + 1;
                
                for(int x=previ;x<i;x++){
                    mp.erase(s[x]);
                }
                
                mp[s[j]] = j;
                temp = s.substr(i,j-i+1);
                ans = max(ans,j-i+1);
            }
            
            else{
                temp += s[j];
                mp[s[j]] = j;
                ans = max(ans,j-i+1);
            }
            
            j++;
        }
        return ans;
    }
};