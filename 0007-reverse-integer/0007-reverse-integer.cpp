class Solution {
public:
    int reverse(int x) {
        long int ans = 0;
        bool is_negative;
        int y;
        if(x < 0){
            y = abs(x);
            is_negative = true;
        }
        else{
            y = x;
            is_negative = false;
        }
        
        while(y > 0){
            if((10*ans) < INT_MAX){
                ans = ans*10 + y%10;
                y = y/10;
            }
            else    return 0;
        }
        if(is_negative)     return -(int)ans;
        else     return (int)ans;
       
    }
};