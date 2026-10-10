class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col,char dig){
        int sr=(row/3)*3;
        int sc=(col/3)*3;
        //row
        for(int j=0;j<9;j++){
            if(board[row][j]==dig){
            return false;
            }
        }
        //column
        for(int i=0;i<9;i++){
            if(board[i][col]==dig){
            return false;
            }
        }
        //grid
        for(int i=sr;i<=sr+2;i++){
            for(int j=sc;j<=sc+2;j++){
                if(board[i][j]==dig){
                    return false;
                }
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board,int row,int col){
        if(row==9){
            return true;
        }
        int nxtRow=row,nxtCol=col+1;
        if(nxtCol==9){
            nxtCol=0;
            nxtRow=row+1;
        }

        if(board[row][col]!='.'){
            return helper(board,nxtRow,nxtCol);
        }
        
        for(char dig='1';dig<='9';dig++){
            if(isSafe(board,row,col,dig)){
            board[row][col]=dig;
            if(helper(board,nxtRow,nxtCol)){
                return true;
            }
            board[row][col]='.';

            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};
