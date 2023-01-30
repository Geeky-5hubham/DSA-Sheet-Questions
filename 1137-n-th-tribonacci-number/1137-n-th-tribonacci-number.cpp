class Solution {
public:
    int tribonacci(int n) {
        
        int k = 4;
        vector<int> v(38) ;
        v = {0,1,1};
        
        int i = 0,j = 0;
        
        int sum = 0;
        
        while( j < 37){
            sum += v[j];
            
            if(j-i+1 == k){
                v[j] = sum;
                v[j+1] = sum;
                sum = sum - v[i];
                
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(j == 37)     v[37] = v[36]+v[35]+v[34];
        
        return v[n];
    }
};