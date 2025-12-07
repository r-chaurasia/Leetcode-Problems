class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.length();
        reverse(num.begin() , num.end());
        int x;
        int i=0;

        while (i<n) {
            if (num[i] != '0') {
                x = i;
                break;
            }
            i++;
        }

        string ans = num.substr(x,n);

        reverse(ans.begin() , ans.end());

        return ans;
    }
};