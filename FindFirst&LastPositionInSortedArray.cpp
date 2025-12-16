class Solution {
public:
    int binarysearch(vector<int>& nums , int target , bool isleft) {
        int l = 0 , r = nums.size()-1;
        int idx = -1;

        while (l <= r) {
            int mid = l + (r - l)/2;

            if (nums[mid] < target) 
                l = mid+1;
            else if (nums[mid] > target)
                r = mid-1;
            else {
                idx = mid;
                if (isleft)
                    r = mid-1;
                else 
                    l = mid+1;
            }
        }

        return idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans = {-1 , -1};

        int left = binarysearch(nums , target , true);
        int right = binarysearch(nums , target , false);

        ans[0] = left;
        ans[1] = right;

        return ans;
    }
};