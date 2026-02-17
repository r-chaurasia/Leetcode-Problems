class Solution {
public:
    int fun(int k, vector<int>& nums) {
        vector<int>v1;

        for(auto i : nums) {
            if(!(i & (1<<k)))
                continue;
            int idx = -1;
            int l = 0 , h = v1.size()-1;
            while(l <= h) {
                int mid = (l+h)/2;
                if(v1[mid] >= i) {
                    idx = mid;
                    h = mid-1;
                }
                else 
                    l = mid+1;
            }

            if(idx == -1)
                v1.push_back(i);
            else
                v1[idx] = i;
        }

        return v1.size();
    }
    int longestSubsequence(vector<int>& nums) {
        int m = -1e6;
        for(int i=0 ; i<=31 ; i++) {
            int len = fun(i, nums);
            m = max(m , len);
        }

        return m;
    }
};