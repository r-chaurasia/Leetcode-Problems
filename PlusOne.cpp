class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n-1;

        while (i>=0) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }
            else {
                digits[i] = 0;
                i--;
            }
        }

        vector<int> newArray(n+1,0);
        newArray[0] = 1;

        return newArray;

    }
};