class Solution {
private:
    int solve(int i, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if (dp[i][amount]!=-2) return dp[i][amount];
        if (amount == 0) return 0;
        int take_go = 1e5, take_stay = 1e5;
        if (i == 0){
            if (amount%coins[i]==0){
                return amount/coins[i];
            }
            else return 1e5;
        }
        if (coins[i]<=amount){
            take_go = 1+solve(i-1, amount-coins[i], coins, dp);
            take_stay =  1+solve(i, amount-coins[i], coins, dp);
        }
        int not_take_go = solve(i-1, amount, coins, dp);

        return dp[i][amount] = min(take_stay, min(take_go, not_take_go));
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -2));
        int res = solve(coins.size()-1, amount, coins, dp);
        if (res == 1e5) return -1;
        else return res;
    }
};