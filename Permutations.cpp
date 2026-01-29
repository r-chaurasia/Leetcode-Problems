class Solution {
public:
    void fun (vector<vector<int>>&ans , vector<int>ip , vector<int>op , int n) {
        if (op.size() == n) {
            ans.push_back(op);
            return;
        }
        for (int i=0 ; i<ip.size() ; i++) {
            int temp = ip[i];
            op.push_back(temp);
            ip.erase(ip.begin() + i);

            fun(ans , ip , op , n);

            op.pop_back();
            ip.insert(ip.begin() + i , temp);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int>ip , op;
        vector<vector<int>>ans;

        fun(ans , nums , op , n);
        return ans;
    }
};