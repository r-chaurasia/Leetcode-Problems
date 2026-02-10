class Solution {
public:
    int dp[201][201];
    int fun(int i, int j, vector<vector<int>>& t, int n) {
        if(i >= n)
            return 0;
       
        if(dp[i][j] != -1e5)
            return dp[i][j];


        int a = t[i][j] + fun(i+1, j, t, n);
        int b = t[i][j] + fun(i+1, j+1, t, n);


        return dp[i][j] = min(a,b);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int r = triangle.size();
        for(int i=0; i<r; i++) {
            for(int j=0; j<r; j++)
                dp[i][j] = -1e5;
        }
        return fun(0, 0, triangle, r);
    }
};
