class Solution {
public:
    // Idea: implement the rules
    // Time complexity O(m*n)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int i = 0;
        int j = 0;
        int cnt = 0;
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}; // left down right up
        int d = 0;
        while(cnt < m*n){
            ans.push_back(matrix[i][j]);
            matrix[i][j] = 101;
            if(i+dir[d][0]<0 || i+dir[d][0]>=matrix.size() ||
            j+dir[d][1]<0 || j+dir[d][1]>=matrix[0].size() || matrix[i+dir[d][0]][ j+dir[d][1]] == 101){
                d = (d+1) % 4;
            }
            i = i + dir[d][0];
            j = j + dir[d][1];
            cnt++;
        }
        return ans;
    }
};
