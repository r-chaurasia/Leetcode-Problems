class Solution {
public:
    int dp[38];
    
    int count(int n) {
        if(n < 0)
            return 0;
        if(n == 0)
            return dp[n] = 0;
        if(n == 1)
            return dp[1] = 1;
        if(n == 2)
            return dp[2] = 1; 

        if(dp[n] != -1)
            return dp[n];

        return dp[n] = count(n-1) + count(n-2) + count(n-3);
    }
    int tribonacci(int n) {
        memset(dp, -1, sizeof(dp));
        return count(n);
    }
};