class Solution {
public:
    int dp[100001][2][2];
    int profit(int i, vector<int>& prices, int t, int k) {
        if(i >= prices.size() || k == 2)
            return 0;
        
        if(dp[i][t][k] != -1)
            return dp[i][t][k];

        int a=0 , b=0;

        if(t == 0) {
            a = (-prices[i]) + profit(i+1, prices, 1, k);
            b = profit(i+1, prices, t, k);
        }
        else {
            a = prices[i] + profit(i+1, prices, 0, k+1);
            b = profit(i+1, prices, t, k);
        }
 
        return dp[i][t][k] = max(a,b);
    }
    int maxProfit(vector<int>& prices) {
        
        for(int i=0 ; i<100001 ; i++) {
            for(int j=0 ; j<2 ; j++) {
                for(int k=0 ; k<2 ; k++)
                    dp[i][j][k] = -1;
            }
        }
        return profit(0, prices, 0, 0);
    }
};