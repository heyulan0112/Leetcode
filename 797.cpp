class Solution {
public:
    // Linklist graph
    // memo to save every node to n-1 all paths that through node x
    // map<int,vector<vector<int>>> from x to n-1 all paths
    // Idea: use backtracking and using map to avoid re-walking the same sub-paths
    unordered_map<int,vector<vector<int>>> mp;
    vector<vector<int>> allPaths(vector<vector<int>>& graph, int curr){
        if(curr == graph.size()-1){
            return {{curr}};
        }
        vector<vector<int>> ans;
        if(mp.count(curr)==0)
            mp[curr] = {};
        for(int i=0;i<graph[curr].size();i++){
            if(mp.count(graph[curr][i])>0 && mp[graph[curr][i]].size()>0){
                // If visit this node before then just fetch paths from map
                for(auto v:mp[graph[curr][i]]){
                    v.insert(v.begin(),curr);
                    ans.push_back(v);
                    mp[curr].push_back(v);
                }
            }
            else{
                // If never visit this node before then recursive to find this neighor's all paths
                vector<vector<int>> sub = allPaths(graph, graph[curr][i]);
                for(auto v:sub){
                    v.insert(v.begin(),curr);
                    ans.push_back(v);
                    mp[curr].push_back(v);
                }
            }
        }
        return ans;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans = allPaths(graph,0);
        return ans;
    }
};