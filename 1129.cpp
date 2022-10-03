class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto v:redEdges){
            graph[v[0]].push_back({v[1],0});
        }
        for(auto v:blueEdges){
            graph[v[0]].push_back({v[1],1});
        }
        vector<int> dist(n,-1);
        queue<vector<int>> q;
        q.push({0,0,-1});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int curr_node = curr[0];
            int curr_step = curr[1];
            int curr_color = curr[2];
            dist[curr_node] = (dist[curr_node] != -1)? dist[curr_node] : curr_step;
            // Must use &adj not adj here because we need to change its first value to be -1 after entering the queue, if we not use & when the value inside queue will never be -1 so visited node will be revisit in future
            for(auto &adj:graph[curr_node]){
                if(adj.first != -1 && adj.second != curr_color){
                    q.push({adj.first,curr_step+1,adj.second});
                    adj.first = -1;
                }
            }
        }
        return dist;
    }
};