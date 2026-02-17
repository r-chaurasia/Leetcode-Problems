class Solution {
  public:
    int dp[101][101];
    int ans(int i, int j, vector<int>&arr) {
        if(i >= j)
            return 0;
        if(dp[i][j] !=-1)
            return dp[i][j];
        int a = 0;
        int m = 1e9;
        for(int k=i ; k<=j-1 ; k++) {
            a = arr[i-1]*arr[k]*arr[j] + ans(i, k, arr) + ans(k+1, j, arr);
            m = min(m ,a);
        }
       
        return dp[i][j] = m;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        memset(dp, -1, sizeof(dp));
        return ans(1, arr.size()-1, arr);
    }
};
