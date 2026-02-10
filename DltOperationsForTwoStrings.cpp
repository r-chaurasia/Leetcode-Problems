class Solution {
public:
    int dp[501][501];
    int fun(int i, int j, string& s, string& t, int n, int m) {
        if(i >= n || j >= m)
            return 0;
       
        int a=0, b=0, c=0;
        if(dp[i][j] != -1e5)
            return dp[i][j];


        if(s[i] == t[j])
            a = 1 + fun(i+1, j+1, s, t, n, m);
       
        b = fun(i+1, j, s, t, n, m);
        c = fun(i, j+1, s, t, n, m);


        return dp[i][j] = max({a, b, c});
    }
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();


        for(int i=0 ; i<501 ; i++) {
            for(int j=0 ; j<501 ; j++)
                dp[i][j] = -1e5;
        }


        int a = fun(0, 0, s, t, n, m);


        return m + n - 2*a;
    }
};
