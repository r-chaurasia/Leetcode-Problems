class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int el;
        int n = nums.size();

        for (int i=0 ; i<n ; i++) {
            if (count == 0) {
                count++;
                el = nums[i];
            }
            else if (nums[i] == el) 
                count++;
            else
                count--;
        }

        int ans = 0;

        for (int i=0 ; i<n ; i++) {
            if (nums[i] == el)
                ans++;
        }

        if (ans > n/2)
            return el;
        return -1;
    }
};
