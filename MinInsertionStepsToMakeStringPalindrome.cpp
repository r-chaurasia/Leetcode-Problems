class Solution {
public:
    int dp[501][501];
    int fun(int i, int j, string& s, string& t, int n) {
        if(i >= n || j >= n)
            return 0;
       
        int a=0, b=0, c=0;
        if(dp[i][j] != -1e5)
            return dp[i][j];


        if(s[i] == t[j])
            a = 1 + fun(i+1, j+1, s, t, n);
       
        b = fun(i+1, j, s, t, n);
        c = fun(i, j+1, s, t, n);


        return dp[i][j] = max({a, b, c});
    }
    int minInsertions(string s) {
        string t;
        int n = s.size();


        for (int i = n-1 ; i >= 0 ; i--) {
            t += s[i];
        }


        for(int i=0 ; i<501 ; i++) {
            for(int j=0 ; j<501 ; j++)
                dp[i][j] = -1e5;
        }


        int m = fun(0, 0, s, t, n);


        return n - m;
    }
};
