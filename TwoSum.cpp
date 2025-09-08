class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        
        int n = arr.size();
        vector<int> ans(2);

        for (int i = 0 ; i < n ; i++) {
            for (int j = i+1 ; j < n ; j++) {
                if (arr[i] + arr[j] == target) {
                    ans[0] = i;
                    ans[1] = j;
                    break;
                }
            }
        }

        return ans;
    }
};