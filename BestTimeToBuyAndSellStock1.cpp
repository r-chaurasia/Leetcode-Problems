class Solution {
public:
    int dp[100001][3];
    int profit(int i, vector<int>& prices, int t) {
        if(i >= prices.size() || t == 2)
            return 0;
        
        if(dp[i][t] != -1)
            return dp[i][t];

        int a=0 , b=0;

        if(t == 0) {
            a = (-prices[i]) + profit(i+1, prices, 1);
            b = profit(i+1, prices, t);
        }
        if(t == 1) {
            a = prices[i] + profit(i+1, prices, 2);
            b = profit(i+1, prices, t);
        }
        
        return dp[i][t] = max(a,b);
    }
    int maxProfit(vector<int>& prices) {
        
        for(int i=0 ; i<100001 ; i++){
            for(int j=0 ; j<3 ; j++) 
                dp[i][j] = -1;
        }
        return profit(0, prices, 0);
    }
};