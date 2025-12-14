class Solution {
public:
    int numberOfWays(string corridor) {
        int mod = 1000000007;
        int n = corridor.size();
        int count = 0;

        for (char c : corridor){
            if (c == 'S') 
                count++;
        }

        if (count == 0 || count % 2 != 0) 
            return 0;

        count = 0;
        long long ans = 1;
        int i = 0, p = 0; 
        bool flag = false;

        while (i < n){
            if (corridor[i] == 'S'){
                count++;
                if (count % 2 == 0){
                    flag = true;
                } 
                else if (count > 2){
                    ans = (ans * (p + 1)) % mod;
                    count = 1; flag = false; p = 0;
                }
            } 
            else if (flag)
                p++;
            
            i++;
        }

        return (int)ans;
    }
};