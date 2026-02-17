class Solution {
public:
    int dp[303][303];
    int ans(int i, int j, vector<int>&arr) {
        if(i > j)
            return 0;
        if(dp[i][j] !=-1)
            return dp[i][j];
        long long int a = 0;
        long long int m = INT_MIN;
        for(int k=i ; k<=j ; k++) {
            a = arr[i-1]*arr[k]*arr[j+1] + ans(i, k-1, arr) + ans(k+1, j, arr);
            m = max(m ,a);
        }
       
        return dp[i][j] = (int)m;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        return ans(1, nums.size()-2, nums);
    }
};