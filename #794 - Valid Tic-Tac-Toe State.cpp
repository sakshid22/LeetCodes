// #794
class Solution {
public:
    int count(vector<string> &board, char judge)
    {
        int ans=0;
        for(int i=0;i<9;i++)
            if(board[i%3][i/3]==judge)
                ans++;
        return ans;
    }
    
    bool win(vector<string> &board, char judge)    // If 0 or X win
    {
        //diagonal
        if(board[0][0] ==judge && board[1][1]==judge && board[2][2]==judge)  return true;
        if(board[0][2] ==judge && board[1][1]==judge && board[2][0]==judge)  return true;
        
        //row
        for(int r=0; r<3; r++)
            if(board[r][0] ==judge && board[r][1]==judge && board[r][2]==judge) return true;
        //column
        for(int c=0; c<3; c++)
            if(board[0][c]== judge && board[1][c] == judge && board[2][c]== judge) return true;
        return false;
    }
      
    bool validTicTacToe(vector<string>& board) {
       int no=count(board,'O'), nx=count(board, 'X');
       bool xwin =win(board,'X'), owin =win(board, 'O');
        if(no>nx)           return false;   //0 cant be greater than X
        if(abs(no-nx)>=2)   return false;   //only 2 player game
        if(xwin && owin )   return false;   // both cant win
        if(xwin && no>=nx)  return false;   //if x wins, O can't play anymore
        if(owin && nx>no)   return false;   //if O wins, X can't play anymore
        return true;
            
        
    }
};