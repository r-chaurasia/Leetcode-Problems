class Solution {
public:
    int dp[2001][2001];
    bool check(int i, int j, string& s) {
        while(i <= j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else
                return false;  
        }
        return true;
    }
    int ans(int i, int j, string& s) {
        if(i >= j || check(i, j, s))
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int a = 0;
        int m = INT_MAX;


        for(int k=i ; k<=j-1; k++) {
            if(check(i, k, s) == 1) {
                a = 1 + ans(k+1, j, s);
                m = min(m, a);
            }
        }


        return dp[i][j] = m;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return ans(0, s.size()-1, s);
    }
};
