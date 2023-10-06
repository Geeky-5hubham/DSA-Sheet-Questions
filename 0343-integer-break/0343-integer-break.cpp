class Solution {
public:
    
    
    int integerBreak(int n) {
        if( n == 2) return 1;
        
        if( n == 3) return 2;
        
        int count = 0;
        
        int ans;
        
        for(int i = 0 ; n >= 3; i++){
             n-=3;
             count++;
        } 

        if(n == 0){ 
            ans = pow(3 , count);
        }
        
        else if (n == 1){ 
            ans = pow(3 , count-1);
            ans*= 4;
        }
        
        else if ( n == 2){ 
            ans = pow(3 , count);
            ans*= 2;
        }
        return ans;
    }
    
    // 7  2*3*2 = 12
    // 8  2*3*3 = 18
    // 9  3*3*3 = 27
    //10  2*3*3*2 = 36
};