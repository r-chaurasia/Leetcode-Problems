class Solution {
public:
    map<string, int> dp;
    int check(string s , string p) {
        if(p.size() > s.size())
            return 0;
        for(int i=0 ; i<p.size() ; i++) {
            if(s[i] != p[i])
                return 0;
        }

        return 1;
    }
    bool wb(string temp , string s , vector<string>& ip) {
        if(check(s , temp) == 0)
            return 0;
        if(temp.size() > s.size())
            return 0;
        if(temp == s)
            return 1;

        int m=0;
        if(dp.find(temp) != dp.end())
            return dp[temp];
        for(int i=0 ; i<ip.size() ; i++) {
            string t = temp;
            t += ip[i];
            m = m  |  wb(t , s , ip);
        }
        dp[temp] = m;
        return m;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.clear();
        return wb("" , s , wordDict);
    }
};