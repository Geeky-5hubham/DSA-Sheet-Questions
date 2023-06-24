class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        
        int i = 0;
        int j = 0;
        
        int c = 0;
        int ans = INT_MIN;
        
        while(j < n){
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                c++;
            }
            
            if(j-i+1 == k){
                ans = max(ans,c);
                
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                    c--;
                }
                i++;
                j++;
            }
            
            else{
                j++;
            }
        }
        
        return ans;
    }
};