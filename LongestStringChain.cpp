bool comp(string& s, string& t){
    return s.size() < t.size();
}
class Solution {
public:
    int dp[1001][1001];
    bool check(string& s, string& t) {
        if(t.size() != s.size()+1)
            return 0;
        
        int i=0, j=0;

        while(i<s.size() && j<t.size()){
            if(s[i] == t[j])
                i++;
            j++;
        }

        return i == s.size();
    }
    int fun(int i, int prev, vector<string>& nums) {
        if(i >= nums.size())
            return 0;

        if(dp[i][prev+1] != -1)
            return dp[i][prev+1];

        int a=0 , b=0 , m=0;

        if(prev == -1 || (check(nums[prev], nums[i]) == 1)){
            a = 1 + fun(i+1, i, nums);
            m = max(m ,a);
        }
        b = fun(i+1, prev, nums);
        m = max(m ,b);
        
        return dp[i][prev+1] = m;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin() , words.end() , comp);

        int prev = -1;
        memset(dp,-1,sizeof(dp));
        return fun(0, prev, words);
    }
};