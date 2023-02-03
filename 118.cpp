class Solution {
public:
    // Idea: implement rules
    // Time complexity is O(numRows^2 = size of this triangle)
    vector<vector<int>> generate(int numRows) {
        // up + upper-left
        vector<vector<int>> pascal;
        pascal.push_back({});
        pascal[0].push_back(1);
        for(int i=1;i<numRows;i++){
            pascal.push_back({});
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    pascal[i].push_back(1);
                }
                else{
                    pascal[i].push_back(pascal[i-1][j-1] + pascal[i-1][j]);
                }
            }
        }
        return pascal;
    }
};
