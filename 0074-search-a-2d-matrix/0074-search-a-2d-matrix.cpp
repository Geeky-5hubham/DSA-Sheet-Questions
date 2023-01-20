class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        int row = matrix.size();
        int col = matrix[0].size();
        /* Better than bruteforce
        int i = 0;
        int j = col-1;
        
        while(i<row && j>=0){
            if(matrix[i][j] == target)  return true;
            else if (matrix[i][j] < target)     i++;
            else    j--;
        }
        return false; */
        int s=0;
        int e=row*col-1;
        int mid;
        
        while(s<=e){
            mid = s+(e-s)/2;
            int i = mid/col;
            int j = mid%col;
            
            if(matrix[i][j] == target)  return true;
            else if(matrix[i][j] > target)  e = mid-1;
            else    s=mid+1;
        }
        return false;
    }
};