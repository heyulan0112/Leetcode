class Solution {
public:
    // Idea: using Longest common substring DP template to solve it
    // Time complexity is O(n)
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<n1+1;i++){
            for(int j=1;j<n2+1;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return n1 + n2 - 2*dp[n1][n2];
    }
};