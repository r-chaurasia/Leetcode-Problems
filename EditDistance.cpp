class Solution {
public:
    int edit(int i, int j, string& w1, string& w2) {
        if(i < 0)
            return j+1;
        if(j < 0)
            return i+1;
        
        if(w1[i] == w1[j])
            return edit(i-1, j-1, w1, w2);
        
        // insert
        int a = edit(i, j-1, w1, w2);
        // delete
        int b = edit(i-1, j, w1, w2);
        // replace
        int c = edit(i-1, j-1, w1, w2);

        return 1 + min({a, b, c});
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        return edit(m-1, n-1, word1, word2);
    }
};