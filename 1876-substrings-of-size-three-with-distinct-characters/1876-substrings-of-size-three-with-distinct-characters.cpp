class Solution {
public:
    int countGoodSubstrings(string s) {
        int k = 3;
        map<char,int> mp;
        int x = 0;
        int i = 0 , j = 0 , count = 0;
        
        while(j<s.size()){
            mp[s[j]]++;
            
            if(j-i+1 == k){
                for (auto i = mp.begin(); i != mp.end(); i++)
                {
                    if (i->second == 1)
                        x++;
                }
                if(x == 3)      count++;
                x = 0;
                mp[s[i]]--;
                i++;
                j++;
            }
            
            else{
                j++;
            }
            
            
        }
        return count;
    }
};