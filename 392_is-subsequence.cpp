class Solution {
private:
    bool f(int i, int j, string s, string t, vector<vector<int>>& dp){
        if (i<0) return true;
        if (j<0) return false;

        if (dp[i][j]!=-1) return dp[i][j]; 
        if (t[j] == s[i]){
            return dp[i][j]=f(i-1, j-1, s, t, dp);
        }
        else return dp[i][j] = f(i, j-1, s, t, dp);
    }
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return f(s.size()-1, t.size()-1, s, t, dp);
    }
};