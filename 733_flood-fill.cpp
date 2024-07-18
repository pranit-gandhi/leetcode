class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int initial_color = image[sr][sc];

        vector<vector<int>> res = image;
        res[sr][sc] = color;
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        q.push({sr, sc});
        vis[sr][sc] = 1;

        while (!q.empty()){
            int i, j;
            tie(i, j) = q.front();
            q.pop();

            if (i+1<n && !vis[i+1][j] && image[i+1][j]==initial_color){
                q.push({i+1, j});
                vis[i+1][j] = 1;
                res[i+1][j] = color;
            }

            if (i-1>=0 && !vis[i-1][j] && image[i-1][j]==initial_color){
                q.push({i-1, j});
                vis[i-1][j] = 1;
                res[i-1][j] = color;
            }

            if (j+1<m && !vis[i][j+1] && image[i][j+1]==initial_color){
                q.push({i, j+1});
                vis[i][j+1] = 1;
                res[i][j+1] = color;
            }

            if (j-1>=0 && !vis[i][j-1] && image[i][j-1]==initial_color){
                q.push({i, j-1});
                vis[i][j-1] = 1;
                res[i][j-1] = color;
            }
        }

        return res;
    }   
};