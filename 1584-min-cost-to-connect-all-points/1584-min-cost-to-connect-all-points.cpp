class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
         int n = points.size();
        vector<bool> visited(n, false);
        vector<int> minDist(n, INT_MAX);
        int totalCost = 0;
        minDist[0] = 0;
        for (int i = 0; i < n; i++)
        {
            int index = -1;
            for (int j = 0; j < n; ++j)
            {
                if (!visited[j] && (index == -1 || minDist[j] < minDist[index]))
                {
                    index = j;
                }
            }
            visited[index] = true;
            totalCost=totalCost+minDist[index];
            for (int v=0;v<n;v++)
            {
                if (!visited[v])
                {
                    int dist = abs(points[index][0] - points[v][0]) + abs(points[index][1] - points[v][1]);
                    minDist[v] = min(minDist[v], dist);
                }
            }
        }
        return totalCost;
    }    
    
};