class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves = 0;
      
      while(target != 1)
      {
        if(maxDoubles == 0) return (target-1 + moves);
        
        if(maxDoubles != 0 && target%2 == 0)
        {
          target /= 2;
          maxDoubles--;
          moves++;
        }
        
        else
        {
          target--;
          moves++;
        }
         
      }
      
      return moves;
    }
};