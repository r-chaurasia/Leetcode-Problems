class Solution {
  public:
    int dp[1001][1001];
    int count(int i, int n, vector<int>& arr, int target, int k) {
        if(k > target)
            return 0;
        if(i >= n) {
            if(k == target)
                return 1;
            else
                return 0;
        }
        if(dp[i][k] != -1e9)
            return dp[i][k];
           
        int a = count(i+1, n, arr, target, k);
        int b = count(i+1, n, arr, target, k+arr[i]);
       
        return dp[i][k] = a+b;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        for(int i=0; i<arr.size(); i++) {
            for(int k=0; k<1000; k++)
                dp[i][k] = -1e9;
        }
           
        return count(0, arr.size(), arr, target, 0);
    }
};
