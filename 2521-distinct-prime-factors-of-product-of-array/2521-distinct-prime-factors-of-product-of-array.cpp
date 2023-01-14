class Solution {
   private:
    unordered_set<int> primeFactors(int n){
            unordered_set<int> ans;
            int c=2;
            while(n>1)
            {
                if(n%c==0){
                ans.insert(c);
                n/=c;
                }
                else c++;
            }
            return ans;
    }
    
    public:
    int distinctPrimeFactors(vector<int>& nums) {
      
        vector<unordered_set<int>> v;

        for(int i = 0;i<nums.size();i++){
            unordered_set<int> temp= primeFactors(nums[i]);
            v.push_back(temp);
        }

        unordered_set<int> ans;

        for(int i=0;i<v.size();i++){
            for (auto itr = v[i].begin(); itr != v[i].end(); itr++) {
                ans.insert(*itr) ;
            }
        }
        return ans.size();
        
        
    }
};