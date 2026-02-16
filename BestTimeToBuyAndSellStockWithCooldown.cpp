class Solution {
public:
    int dp[30001][3];
    int profit(int i, vector<int>& prices, int t) {
        if(i >= prices.size())
            return 0;
        
        if(dp[i][t] != -1)
            return dp[i][t];

        int a=0 , b=0;

        if(t == 0) {
            a = (-prices[i]) + profit(i+1, prices, 1);
            b = profit(i+1, prices, t);
        }
        if(t == 1) {
            a = prices[i] + profit(i+2, prices, 0);
            b = profit(i+1, prices, t);
        }

        return dp[i][t] = max(a, b);
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return profit(0, prices, 0);
    }
};