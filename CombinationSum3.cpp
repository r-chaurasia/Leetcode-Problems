class Solution {
public:
    void fun(int i, int k, int n, vector<vector<int>>&ans, vector<int>&op){
        if(k == 0){
            if(n == 0)
                ans.push_back(op);
            return;
        }
        if(n < 0)
            return;
        if(i == 10)
            return;
        
        // not pick
        fun(i+1, k, n, ans, op);

        // pick
        op.push_back(i);
        fun(i+1, k-1, n-i, ans, op);
        op.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>op;

        fun(1, k, n, ans, op);
        return ans;
    }
};