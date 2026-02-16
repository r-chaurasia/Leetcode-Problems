class Solution {
public:
    void fun(vector<int>& c, int i, int t, vector<int>& op, vector<vector<int>>& ans) {
        if(t == 0) {
            ans.push_back(op);
            return;
        }

        for(int j=i ; j<c.size() ; j++) {
            if(j>i && c[j] == c[j-1])
                continue;
            if(c[i] > t)
                break;
            op.push_back(c[j]);
            fun(c, j+1, t-c[j], op, ans);
            op.pop_back();
        }
    } 
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        vector<int>op;
        vector<vector<int>>ans;
        sort(candidates.begin(), candidates.end());

        fun(candidates, 0, target, op, ans);
        return ans;
    }
};

