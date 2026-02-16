class Solution {
public:
    int dp[13][10001];
    int count(int i , vector<int>& coins , int amount) {
    if(amount == 0) 
        return 0;

    if(amount < 0 || i >= coins.size())
        return 1e6;
    
    
    if(dp[i][amount] != -1)
        return dp[i][amount];

    // not pick
    int a = count(i+1 , coins , amount);
    // pick
    int b = 1 + count(i , coins , amount - coins[i]);

    return dp[i][amount] = min(a, b);
}
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int a = count(0 , coins , amount);
        
        if(a == 1e6)
            return -1;
        return a;
    }
};


