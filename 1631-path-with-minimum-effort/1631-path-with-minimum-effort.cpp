class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort(n,vector<int> (m,1e9));
        effort[0][0] = 0;
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>> > pq;    // {effort,row,col}
        pq.push({0,0,0});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int eff = it[0];
            int r = it[1];
            int c = it[2];
            
            
            if(r == n-1 && c == m-1)
                return effort[r][c];
                        
            
            int delRow[4] = {-1,+1,0,0};
            int delCol[4] = {0,0,-1,+1};
            
            for(int i=0;i<4;i++){
                int newRow = r + delRow[i];
                int newCol = c + delCol[i];
                
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m ){
                    int newEffort = max(abs(heights[newRow][newCol] - heights[r][c]),eff);
                    
                    if(newEffort < effort[newRow][newCol]){
                        effort[newRow][newCol] = newEffort;
                        pq.push({newEffort,newRow,newCol});
                    }
               
                }
            }
        }
        return 0;
    }
};