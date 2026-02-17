class Solution {
public:
    int dp[2501][2501];
    int fun(int i, int prev, vector<int>& nums) {
        if(i >= nums.size())
            return 0;

        if(dp[i][prev+1] != -1)
            return dp[i][prev+1];

        int a=0 , b=0;

        if(prev == -1 || nums[i] > nums[prev])
            a = 1 + fun(i+1, i, nums);

        b = fun(i+1, prev, nums);
        
        return dp[i][prev+1] = max(a,b);
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;

        memset(dp, -1, sizeof(dp));

        return fun(0, prev, nums);
    }
};