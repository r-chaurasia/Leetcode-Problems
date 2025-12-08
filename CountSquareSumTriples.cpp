class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        int a , b;
        
        for (int i=1 ; i<=n ; i++) {
            for (int j=1 ; j<=n ; j++) {
                a = i*i + j*j;
                b = sqrt(a);

                if (b <= n && b*b == a)
                    ans++;
            }
        }

        return ans;
    }
};