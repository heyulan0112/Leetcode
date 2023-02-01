class Solution {
public:
    // Idea: record all zero index and use row, col map to track rows and cols that are set zero
    // Time complexity O(m * n)
    void setRow(vector<vector<int>>& matrix, int row){
        for(int j=0;j<matrix[0].size();j++){
            matrix[row][j] = 0;
        }
    }
    void setCol(vector<vector<int>>& matrix, int col){
        for(int i=0;i<matrix.size();i++){
            matrix[i][col] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,bool> row;
        unordered_map<int,bool> col;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int,int>> zero;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    zero.push_back({i,j});
                }
            }
        }
        for(auto p:zero){
            int i = p.first;
            int j = p.second;
            if(row.count(i) == 0){
                row[i] = true;
                setRow(matrix,i);
            }
            if(col.count(j) == 0){
                col[j] = true;
                setCol(matrix,j);
            }
        }
    }
};
