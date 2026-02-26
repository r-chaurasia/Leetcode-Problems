class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans;
        int m = nums.size();

        int low = 0;
        int high = n;

        for(int i=0 ; i<m ; i++) {
            if(i % 2 == 0) {
                ans.push_back(nums[low]);
                low++;
            }
            else {
                ans.push_back(nums[high]);
                high++;
            }
        }

        return ans;
    }
};