class Solution {
public:
    // Idea: use memory to record how many possible dial when stano on digit x with step n to avoid re walk same recursive path
    long long mod = 1e9 + 7;
    
    long long traverse(int curr, int n, vector<vector<int>>& adj, vector<vector<long long>>& dp){
        if(n == 0){
            return 1;
        }
        if(dp[curr][n] != -1)
            return dp[curr][n];
        long long ans = 0;
        for(int i:adj[curr]){
            // goes to find how many possible result in each child node and add them up
            ans = (ans + traverse(i,n-1,adj,dp)) % mod;
        }
        // record it for later use
        dp[curr][n] = ans;
        return ans;
    }

    int knightDialer(int n) {
        vector<vector<int>> adj(10);
        vector<vector<long long>> dp(10,vector<long long>(n,-1));
        adj[0] = {4,6}, adj[1] = {6,8}, adj[2] = {7,9}, adj[3] = {4,8};
        adj[4] = {0,9,3}, adj[5] = {}, adj[6] = {0,1,7}, adj[7] = {2,6};
        adj[8] = {1,3}, adj[9] = {4,2};
        long long ans = 0;
        for(int i=0;i<10;i++){
            ans = (ans + traverse(i,n-1,adj,dp)) % mod;
        }
        return (int)ans;
    }
};