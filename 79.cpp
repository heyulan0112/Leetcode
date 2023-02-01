class Solution {
public:
    // Idea: backtracking, edge case is backtracking ending condition is curr == word.size()-1
    // otherwise it cannot detect the case that word size == 1
    // Time complexity O(m * n * length of word)
    void explore(vector<vector<char>>& board, string& word, int curr, bool& ans, int i, int j){
        if(ans == true){
            return;
        }
        if(curr == word.size()-1 && board[i][j] == word[curr]){
            ans = true;
            return;
        }
        if(board[i][j] != word[curr]){
            ans = false;
            return;
        }
        char val = board[i][j];
        board[i][j] = '.';
        if(i-1>=0 && board[i-1][j]!='.'){
            explore(board,word,curr+1,ans,i-1,j);
        }
        if(i+1<board.size() && board[i+1][j]!='.'){
            explore(board,word,curr+1,ans,i+1,j);
        }
        if(j-1>=0 && board[i][j-1]!='.'){
            explore(board,word,curr+1,ans,i,j-1);
        }
        if(j+1<board[0].size() && board[i][j+1]!='.'){
            explore(board,word,curr+1,ans,i,j+1);
        }
        board[i][j] = val;

    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    bool ans = false;
                    explore(board,word,0,ans,i,j);
                    if(ans){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
