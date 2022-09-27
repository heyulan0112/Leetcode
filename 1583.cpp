class Solution {
public:
    // Idea: Time complexity is O(n^3)
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int ans = 0;
        vector<unordered_map<int,int>> mp(n);
        vector<int> dist(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<preferences[i].size();j++){
                mp[i][preferences[i][j]] = j;
            }
        }
        for(auto p:pairs){
            dist[p[0]] = mp[p[0]][p[1]];
            dist[p[1]] = mp[p[1]][p[0]];
        }
        // traverse all people
        for(int i=0;i<n;i++){
            // dist[i] means i's close degree with its pair people
            // so traverse all close degree is closer than dist[i]
            for(int j=0;j<dist[i];j++){
                // x is i's prefer people in close degree j
                int x = preferences[i][j];
                // also traverse all x's close degree that are closer than dist[x]
                for(int k=0;k<dist[x];k++){
        // if one of x's close degree that are closer than dist[x] is with i then it is bi direction
                    // so i's original pair people is an unhappy person and ans++
                    if(i == preferences[x][k]){
                        ans++;
                        j = n;
                        k = n;
                    }
                }
            }
        }
        return ans;
    }
};