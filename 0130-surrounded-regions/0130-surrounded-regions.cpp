class Solution {
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    bool isValid(int i,int j,int n, int m){
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        
        return true;
    }

    void dfs(vector<vector<char>>& board, int i,int j,int n,int m){
        board[i][j]='S';
        for(int k=0;k<4;k++){
            int row = i+x[k];
            int col = j+y[k];
            
            if(isValid(row,col,n,m) && board[row][col]=='O'){
                dfs(board,row,col,n,m);
            }
        }
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && (i==0 || j==0 || i==n-1 || j==m-1))
                    dfs(board,i,j,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='S')
                    board[i][j]='O';
            }
        }

        return;
    }
};