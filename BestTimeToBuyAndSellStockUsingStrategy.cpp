class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        
        // Base profit with original strategy
        long long baseProfit = 0;
        for (int i = 0; i < n; i++) {
            baseProfit += 1LL * strategy[i] * prices[i];
        }
        
        // Prefix sum of original contributions: strategy[i] * prices[i]
        vector<long long> prefOrig(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefOrig[i + 1] = prefOrig[i] + 1LL * strategy[i] * prices[i];
        }
        
        // Prefix sum of prices
        vector<long long> prefPrice(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefPrice[i + 1] = prefPrice[i] + prices[i];
        }
        
        long long maxDelta = 0;
        int half = k / 2;
        
        // Try every window of length k
        for (int l = 0; l + k <= n; l++) {
            int mid = l + half;
            int r = l + k;
            
            // Original contribution of this window
            long long oldWindow = prefOrig[r] - prefOrig[l];
            
            // New contribution after modification:
            // first half -> 0, second half -> 1
            long long newWindow = prefPrice[r] - prefPrice[mid];
            
            long long delta = newWindow - oldWindow;
            maxDelta = max(maxDelta, delta);
        }
        
        return baseProfit + maxDelta;
    }
};
