class Solution {
public:
    int check(int mid,int A[],int N){
        int c = 0;
        int currSum = 0;
        
        for(int i=0;i<N;i++){
            currSum += A[i];
            
            if(currSum > mid){
                c++;
                currSum = A[i];
            }
        }
        
        c++;
        return c;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M > N)
            return -1;
            
        int low = 0;
        int high = 0;
        
        for(int i=0;i<N;i++){
            low = max(low,A[i]);
            high += A[i];
        }
        
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(check(mid,A,N) > M){
                low = mid+1;
            }
            
            else{
                high = mid-1;
            }
        }
        
        return low;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int A[weights.size()];
        for(int i=0;i<weights.size();i++){
            A[i] = weights[i];
        }
        
        return findPages(A,weights.size(),days);
    }
};