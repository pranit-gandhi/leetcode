class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        vector<vector<int>> res;
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
        queue<tuple<int, int, int>> q;
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));

        q.push({start[0], start[1], 0});
        vis[start[0]][start[1]] = 1;

        while(!q.empty()){
            int x, y, dist;
            tie(x, y, dist) = q.front();
            q.pop();

            if (grid[x][y] <= pricing[1] && grid[x][y] >= pricing[0]){
                pq.push({dist, grid[x][y], x, y});
            }

            if(x-1>=0 && !vis[x-1][y] && grid[x-1][y]>0){
                vis[x-1][y] = 1;
                q.push({x-1, y, dist+1});
            }
            if(x+1<grid.size() && !vis[x+1][y] && grid[x+1][y]>0){
                vis[x+1][y] = 1;
                q.push({x+1, y, dist+1});
            }
            if(y-1>=0 && !vis[x][y-1] && grid[x][y-1]>0){
                vis[x][y-1] = 1;
                q.push({x, y-1, dist+1});
            }
            if(y+1<grid[0].size() && !vis[x][y+1] && grid[x][y+1]>0){
                vis[x][y+1] = 1;
                q.push({x, y+1, dist+1});
            }
        }

        for(int i=0; i<k; i++){
            if (pq.empty()) break;
            int a, b, c, d;
            tie(a, b, c, d) = pq.top();
            res.push_back({c, d});
            pq.pop();
        }

        return res;

    }
};