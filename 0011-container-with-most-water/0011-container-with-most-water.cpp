class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i=0;
        int j=height.size()-1;
    
        int ans = 0;
        int area ;
        while(j>i){
            
            int b = min(height[i],height[j]);
            
            area = (j-i)*b;
            ans = max(ans,area);
            
            if(height[i] <= height[j])
                i++;
            
            else
                j--;
            
        }
        return ans;
    }
};