class Solution {
public:
int dp[1001][1001];
    int fun(int i, int j, string& s, string& t, int m, int n) {
        if(i >= m || j >= n)
            return 0;
       
        int a=0, b=0, c=0;
        if(dp[i][j] != -1)
            return dp[i][j];


        if(s[i] == t[j])
            a = 1 + fun(i+1, j+1, s, t, m, n);
       
        b = fun(i+1, j, s, t, m, n);
        c = fun(i, j+1, s, t, m, n);


        return dp[i][j] = max({a, b, c});
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
       
        return fun(0, 0, text1, text2, text1.size(), text2.size());
    }
};
