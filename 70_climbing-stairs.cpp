class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1, prev1 = 2, cur;
        if (n==1) return 1;

        for(int i=3; i<=n; i++){
            cur = prev1+prev2;
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};