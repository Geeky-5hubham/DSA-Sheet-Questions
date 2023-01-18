class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        map<pair<int,int>,bool> mp;
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if( i != j && mp.find(make_pair(i,j)) == mp.end()){
                    swap(matrix[i][j],matrix[j][i]);
                    mp[make_pair(i,j)] == true;
                    mp[make_pair(j,i)] == true;
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};