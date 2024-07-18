class Solution {
private:
    bool f(int jd, vector<int>& stones, int ci, vector<vector<int>>& dp){
        if (ci>=stones.size()) return false;
        if (stones.size()-1 == ci) return true;
        if (dp[ci][ci-jd]!=-1) return dp[ci][ci-jd];

        bool a=false, b=false, c=false;
        
        for(int j = ci+1; j<stones.size(); j++){
            if (stones[ci]+jd==stones[j]) a = f(jd, stones, j, dp);
            if (stones[ci]+jd-1 == stones[j]) b = f(jd-1, stones, j, dp);
            if (stones[ci]+jd+1 == stones[j]) c = f(jd+1, stones, j, dp);
        }

        
        return dp[ci][ci-jd] = max(c, max(a, b));
    }
public:
    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp(stones.size(), vector<int>(stones.size(), -1));
        return f(0, stones, 0, dp);
    }
};