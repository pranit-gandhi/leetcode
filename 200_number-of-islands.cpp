class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[i][j] = 1;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int m=0; m<4; m++){
                int ni = i+dx[m], nj = j+dy[m];
                if (ni>=0 && ni<grid.size() &&
                    nj>=0 && nj<grid[0].size()
                    && !vis[ni][nj] && grid[ni][nj]=='1'){
                        dfs(ni, nj, vis, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));

        int count = 0;
        for(int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if (grid[i][j]=='1' && !vis[i][j]){
                    count+=1;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return count;
    }
};