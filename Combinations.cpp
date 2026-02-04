class Solution {
public:
    void combinations(vector<vector<int>>& ans, vector<int>& ip, vector<int>& op, int n) {
        if (op.size() == n) {
            ans.push_back(op);
            return;
        }

        for (int i=0 ; i<ip.size() ; i++) {
            vector<int>v1(ip), v2(op);

            v2.push_back(v1[i]);

            for(int j=0 ; j<=i ; j++)
                v1.erase(v1.begin());

            combinations(ans, v1, v2, n);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ip;
        vector<int> op;

        for(int i=1 ; i<=n ; i++)
            ip.push_back(i);

        combinations(ans , ip , op , k );

        return ans;
    } 
};