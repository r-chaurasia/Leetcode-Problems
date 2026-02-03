class Solution {
public:
    void fun(vector<vector<int>>& ans , vector<int> ip , vector<int> op , int n) {
        if (ip.size() == 0)
            return;
        
        for (int i=0 ; i<ip.size() ; i++) {
            vector<int>v1(ip) , v2(op);

            v2.push_back(v1[i]);
            for(int j=0 ; j<=i ; j++)
                v1.erase(v1.begin());

            ans.push_back(v2);
            fun(ans, v1 , v2 , n);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ip;
        vector<int>op;
        vector<vector<int>> ans;
        ans.push_back(op);

        fun(ans , nums , op , nums.size());
        return ans;
    }
};