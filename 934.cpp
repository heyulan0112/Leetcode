class Solution {
public:
    // Time complexity is O(n^2)
    void DFS(vector<vector<int>>& grid,set<pair<int,int>>& iland,int row,int col){
        int n = grid.size();
        grid[row][col] = 0;
        iland.insert({row,col});
        if(row-1>=0 && grid[row-1][col] == 1){
            DFS(grid,iland,row-1,col);
        }
        if(row+1<n && grid[row+1][col] == 1){
            DFS(grid,iland,row+1,col);
        }
        if(col-1>=0 && grid[row][col-1] == 1){
            DFS(grid,iland,row,col-1);
        }
        if(col+1<n && grid[row][col+1] == 1){
            DFS(grid,iland,row,col+1);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        set<pair<int,int>> iland1;
        set<pair<int,int>> iland2;
        bool f = true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && f){
                    f = false;
                    DFS(grid,iland1,i,j);
                }
                else if (grid[i][j] == 1 && f == false){
                    DFS(grid,iland2,i,j);
                }
            }
        }
        int shortest = INT_MAX;
        for(auto p1:iland1){
            for(auto p2:iland2){
                shortest = min(shortest,abs(p1.first-p2.first) + abs(p1.second-p2.second) - 1);
            }
        }
        return shortest;
    }
};