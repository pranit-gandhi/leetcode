class Solution {
private:
    pair<bool, double> dfs(int i, int j, vector<vector<pair<int, double>>>& adj, vector<int>& vis){
        if (i==j) return make_pair(true, 1);
        vis[i] = 1;
        
        for (auto adjInfo: adj[i]){
            if (adjInfo.first == j) {
                return make_pair(true, adjInfo.second);
            }
            if (vis[adjInfo.first]) continue;
            else {
                auto call = dfs(adjInfo.first, j, adj, vis);
                if (call.first) return make_pair(true, call.second*adjInfo.second);
                else continue;
            }
        }

        return make_pair(false, double(-1));
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<vector<pair<int, double>>> adj;
        adj.resize(2*equations.size());
        map<string, int> dict;

        int id = 0;
        for(int i=0; i<equations.size(); i++){
            if (dict.find(equations[i][0]) == dict.end()){
                dict[equations[i][0]] =  id++;
            }
            if (dict.find(equations[i][1]) == dict.end()){
                dict[equations[i][1]] =  id++;
            }
            adj[dict[equations[i][0]]].push_back({dict[equations[i][1]], values[i]});
            adj[dict[equations[i][1]]].push_back({dict[equations[i][0]], 1/values[i]});
            
            // adj[dict[equations[i][0]]].push_back({dict[equations[i][0]], 1});
            // adj[dict[equations[i][1]]].push_back({dict[equations[i][1]], 1});
        }
        adj.resize(id);
        vector<double> res;
        for (auto q: queries){
            vector<int> vis(id, 0);
            if (dict.find(q[0]) == dict.end() || dict.find(q[1]) == dict.end()) res.push_back(-1);
            else{
                res.push_back(dfs(dict[q[0]], dict[q[1]], adj, vis).second);
            }
        }

        return res;
    }
};