class Solution {
public:
    // Idea: use dfs to set all edge 'O' blocks to be 'E'
    // then walk through all graph set 'O' to 'X' and 'E' back to 'O'
    // Time complexity is O(m*n)
    void setEdge(vector<vector<char>>& board, int i, int j){
        int m = board.size();
        int n = board[0].size();
        board[i][j] = 'E';
        if(i-1>=0 && board[i-1][j] == 'O'){
            setEdge(board,i-1,j);
        }
        if(i+1<m && board[i+1][j] == 'O'){
            setEdge(board,i+1,j);
        }
        if(j-1>=0 && board[i][j-1] == 'O'){
            setEdge(board,i,j-1);
        }
        if(j+1<n && board[i][j+1] == 'O'){
            setEdge(board,i,j+1);
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            if(board[i][0] == 'O'){
                setEdge(board,i,0);
            }
            if(board[i][n-1] == 'O'){
                setEdge(board,i,n-1);
            }
        }
        for(int j=0;j<n;j++){
            if(board[0][j] == 'O'){
                setEdge(board,0,j);
            }
            if(board[m-1][j] == 'O'){
                setEdge(board,m-1,j);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'E'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
