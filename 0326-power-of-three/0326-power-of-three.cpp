class Solution {
public:
    bool isPowerOfThree(int n) {
        int x = pow(3,19);
        if(n>0 && x%n == 0)     return true;
        return false;
    }
};