class Solution {
public:
    int dp[501][501];
    int fun(int i, int prev, vector<int>& arr, int k, int m) {
        if(i >= arr.size())
            return 0;
       
        if(dp[i][prev] != -1e5)
            return dp[i][prev];


        m = max(m, arr[i]);
        int ch1 = 0, ch2 = 0, ch3 = 0;


        if((i-prev+1) == k)
            ch1 = (i-prev+1) * m + fun(i+1, i+1, arr, k, 0);
        else{
            ch2 = (i-prev+1) * m + fun(i+1, i+1, arr, k, 0);
            ch3 = fun(i+1, prev, arr, k, m);
        }


        return dp[i][prev] = max({ch1, ch2, ch3});
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        for(int i=0; i<arr.size(); i++) {
            for(int j=0; j<arr.size(); j++)
                dp[i][j] = -1e5;
        }
        return fun(0, 0, arr, k, 0);
    }
};
