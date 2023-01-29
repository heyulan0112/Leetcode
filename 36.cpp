class Solution {
public:
    // Idea: enumerate all possible cases and check
    // Time complexity O(1)
    bool checkRow(vector<vector<char>>& board){
        for(auto row:board){
            vector<bool> check(9,false);
            for(char c:row){
                if(c == '.'){
                    continue;
                }
                int num = c-'0';
                if(check[num] == true){
                    return false;
                }
                check[num] = true;
            }
        }
        return true;
    }

    bool checkCol(vector<vector<char>>& board){
        for(int j=0; j<board[0].size();j++){
            vector<bool> check(9,false);
            for(int i=0;i<board.size();i++){
                if(board[i][j] == '.'){
                    continue;
                }
                int num = board[i][j] - '0';
                if(check[num] == true){
                    return false;
                }
                check[num] = true;
            }
        }
        return true;
    }

    bool checkGrid(vector<vector<char>>& board, int row, int col){
        vector<bool> check(9,false);
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                if(board[i][j] == '.'){
                    continue;
                }
                int num = board[i][j] - '0';
                if(check[num] == true){
                    return false;
                }
                check[num] = true;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        if(checkRow(board) == false){
            return false;
        }
        if(checkCol(board) == false){
            return false;
        }
        int i = 0;
        while(i<=board.size()-3){
            int j = 0;
            while(j<=board[0].size()-3){
                if(checkGrid(board,i,j) == false){
                    return false;
                }
                j += 3;
            }
            i += 3;
        }
        return true;
    }
};
