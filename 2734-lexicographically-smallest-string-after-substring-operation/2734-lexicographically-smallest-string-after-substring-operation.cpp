class Solution {
public:
    string smallestString(string s) {
       int n = s.size();
        
        if(n == 1)
        {
            if(s[0] == 'a')
                return "z";
            
            else{
                --s[0];
                return s;
            }
        }
        
        int i = 0;
        
        while(i < n && s[i] == 'a')
            i++;
        
        if(i == n){
            s[i-1] = 'z';
        }
        
        while(i < n && s[i] != 'a'){
            s[i]--;
            i++;
        }
        
        return s;
    }
};