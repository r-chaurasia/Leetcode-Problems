class Solution {
public:
    bool check(int i, int j, string& s) {
        while(i <= j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else
                return false;  
        }
        return true;
    }
    void ans(int i, int j, string& s, vector<vector<string>>& sol, vector<string>& op) {
        if(i > j){
            sol.push_back(op);
            return;
        }


        for(int k=i ; k<=j; k++) {
            if(check(i,k,s) == 1) {
                string str = s.substr(i, k-i+1);
                op.push_back(str);
                ans(k+1, j, s, sol, op);
                op.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>sol;
        vector<string>op;


        ans(0, s.size()-1, s, sol, op);
        return sol;
    }
};




