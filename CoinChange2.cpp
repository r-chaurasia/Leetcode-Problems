class Solution {
public:
    int dp[301][5001];
    int fun(int i, int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;
        
        if(amount < 0 || i >= coins.size())
            return 0;
        
        if(dp[i][amount] != -1)
            return dp[i][amount];

        // not pick
        int a = fun(i+1 , amount , coins);
        // pick
        int b = fun(i , amount-coins[i] , coins);

        return dp[i][amount] = a+b;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp , -1 , sizeof(dp));
        
        return fun(0 , amount , coins);
    }
};