class Solution {
    public:
        int specialTriplets(vector<int>& nums) {
                const int MOD = 1e9 + 7;
                        int n = nums.size();

                                vector<long long> right(200001, 0), left(200001, 0);

                                        for (int x : nums) right[x]++;

                                                long long ans = 0;

                                                        for (int j = 0; j < n; j++) {
                                                                    int x = nums[j];
                                                                                right[x]--;  

                                                                                            long long need = x * 2LL;

                                                                                                        if (need <= 200000) {
                                                                                                                        ans = (ans + left[need] * right[need]) % MOD;
                                                                                                                                    }

                                                                                                                                                left[x]++;
                                                                                                                                                        }

                                                                                                                                                                return ans;
                                                                                                                                                                    }
                                                                                                                                                                    };
}