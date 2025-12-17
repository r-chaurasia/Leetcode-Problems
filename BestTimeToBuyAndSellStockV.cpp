class Solution {
    public:
        long long maximumProfit(vector<int>& prices, int k) {
                int n = prices.size();
                        vector<long long> dp_prev(n, 0), dp_curr(n, 0);

                                for (int t = 1; t <= k; t++) {
                                            long long bestLong = -prices[0];   // dp[t-1][j-1] - prices[j]
                                                        long long bestShort = prices[0];   // dp[t-1][j-1] + prices[j]

                                                                    for (int i = 1; i < n; i++) {
                                                                                    dp_curr[i] = max({
                                                                                                        dp_curr[i - 1],                    // no transaction today
                                                                                                                            prices[i] + bestLong,              // normal transaction
                                                                                                                                                -prices[i] + bestShort              // short-selling
                                                                                                                                                                });

                                                                                                                                                                                bestLong = max(bestLong, dp_prev[i - 1] - prices[i]);
                                                                                                                                                                                                bestShort = max(bestShort, dp_prev[i - 1] + prices[i]);
                                                                                                                                                                                                            }
                                                                                                                                                                                                                        dp_prev.swap(dp_curr);
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                        return dp_prev[n - 1];
                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                            };
}