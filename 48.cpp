class Solution {
public:
    // Idea: swap(matrix[i][j],matrix[j][i]) then reverse each rows
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix[0].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<matrix.size();i++){
            int left = 0;
            int right = matrix[0].size()-1;
            while(left < right){
                swap(matrix[i][left],matrix[i][right]);
                left++;
                right--;
            }
        }
    }
};
