class Solution {
public:
    void fun(vector<int>& c, int i, int t, vector<int>& op, vector<vector<int>>& ans) {
        if(i >= c.size()){
            if(t == 0) 
                ans.push_back(op);
            return;
        }

        // not pick
        fun(c, i+1, t, op, ans);
        // pick
        if(c[i] <= t) {
            t -= c[i];
            op.push_back(c[i]);
            fun(c, i, t, op, ans);
            op.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>op;
        vector<vector<int>>ans;

        fun(candidates, 0, target, op, ans);
        return ans;
    }
};