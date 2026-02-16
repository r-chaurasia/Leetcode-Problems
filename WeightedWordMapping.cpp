class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string str;

        for(int i=0 ; i<words.size() ; i++) {
            int t = 0;

            for(char j : words[i])
                t += weights[j - 'a'];

            int mod = t % 26;

            char c = 'z' - mod;

            str += c;
        }

        return str;
    }
};