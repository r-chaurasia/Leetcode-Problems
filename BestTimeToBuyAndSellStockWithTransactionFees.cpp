class Solution {
public:
    int dp[50001][2];
    int profit(int i, vector<int>& prices, int t, int fee) {
        if(i >= prices.size())
            return 0;
        
        if(dp[i][t] != -1)
            return dp[i][t];

        int a=0 , b=0;

        // buy
        if(t == 0) {
            a = (-prices[i]) + profit(i+1, prices, 1, fee);
            b = profit(i+1, prices, t, fee);
        }
        // sell
        if(t == 1) {
            a = prices[i] - fee + profit(i+1, prices, 0, fee);
            b = profit(i+1, prices, t, fee);
        }

        return dp[i][t] = max(a, b);
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        return profit(0, prices, 0, fee);
    }
};