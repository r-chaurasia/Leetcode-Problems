class Solution {
public:
    int dp[201][1001];
    int fun(int i, vector<int>& ip, int target, vector<int>& op) {
        if(i>= ip.size())
            return 0;
        if(target == 0)
            return 1;
        if(target < 0)
            return 0;
        if(dp[i][target] != -1)
            return dp[i][target];

        // not pick
        int a = fun(i+1, ip, target, op);
        // pick
        int b = 0;
        if(ip[i] <= target)
            b = fun(0, ip, target-ip[i], op);
        
        return dp[i][target] = a+b;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>op;
        memset(dp, -1, sizeof(dp));

        return fun(0, nums, target, op);
    }
};