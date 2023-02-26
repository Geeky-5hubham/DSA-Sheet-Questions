class Solution {
private:
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                
                if(board[i][j] == '.'){
                    
                    for(char c='1';c<='9';c++){
                        if(isvalid(board,i,j,c)){
                            
                            board[i][j] = c;
                            if(solve(board) == true)
                                return true;
                            
                            else
                                board[i][j] = '.';
                            
                          }
                        
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isvalid(vector<vector<char>>& board,int row,int col,char c){
        for(int i=0;i<9;i++){
            // Row
            if(board[row][i] == c)
                return false;
            
            // Col
            if(board[i][col] == c)
                return false;
            
            // 9x9 Square
            if(board[(row/3)*3 + i/3][(col/3)*3 + i%3] == c)
                return false;
         
        }
        return true;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};