class Solution {
public:
    int mySqrt(int x) {
        long int lo = 0;
        long int hi = x;
        long int res;
        
        while(lo<=hi){
            long int mid = lo+(hi-lo)/2;
            
            if(mid*mid == x)    return mid;
            else if(mid*mid>x)  hi = mid-1;
            else{
                res = mid;
                lo=mid+1;
            }
        }
        return res;
    }
};