class Solution {
public:
    vector<int> digits(int num){
        vector<int> ans;
        
        while(num > 0 ){
            ans.push_back(num%10);
            num = num/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    int divisorSubstrings(int num, int k) {
        int i=0;
        int j=0;
        int n=0;
        int count=0;
        
        vector<int> nums = digits(num);
        
        while(j < nums.size()){
            
            n=n*10 + nums[j];
            if(j-i+1==k){
                if(n != 0 && num%n == 0) count++;
                n=n-nums[i]*pow(10,k-1);
                i++;
                j++;
            }
            else
            j++;
        
        }
        return count;
    }
};