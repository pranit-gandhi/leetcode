class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj;
        vector<int>minDists(n+1, 10e6);
        minDists[0] = 0;
        priority_queue<pair<int, int>> pq;
        adj.resize(n+1);

        for (auto edge: times){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        pq.push({0, k});
        minDists[k] = 0;

        while (!pq.empty()){
            int e, n;
            tie(e, n) = pq.top();
            pq.pop();

            for(auto adjm: adj[n]){
                int adje = adjm.second, adjn = adjm.first;
                if (e+adje<minDists[adjn]){
                    minDists[adjn] = e+adje;
                    pq.push({minDists[adjn], adjn});
                }
            }
        }

        if (*max_element(minDists.begin(), minDists.end()) == 10e6) return -1;
        else return *max_element(minDists.begin(), minDists.end());        
    }
};