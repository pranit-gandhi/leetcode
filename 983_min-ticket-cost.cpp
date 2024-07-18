class Solution {
private:
    int f(int i, int cd, vector<int>& days, vector<int>& costs, vector<vector<int>>& dp){
        if (i==days.size()) return 0;
        if (dp[i][cd]!=-1) return dp[i][cd];
        if (cd>days[i]) return f(i+1, cd, days, costs, dp);
        
        if (cd==days[i]){
            int go1 = costs[0] + f(i+1, cd+1, days, costs, dp);
            int go7 = costs[1] + f(i+1, cd+7, days, costs, dp);
            int go30 = costs[2] + f(i+1, cd+30, days, costs, dp);
            return dp[i][cd] = min(go1, min(go7, go30));
        }
        else return dp[i][cd] = f(i, days[i], days, costs, dp);

    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> dp(days.size()+1, vector<int>(10000, -1));
        return f(0, 1, days, costs, dp);
    }
};