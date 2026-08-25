class Solution {
public:

    bool palindromic(string& s, int i, int j) {
        if(i >= j) {
            return true;
        }

        if(s[i] != s[j]) {
            return false;
        }

        return palindromic(s, i + 1, j - 1);
    }

    void solve(string& s, vector<vector<string>>& ans,
               vector<string>& temp, int i) {

        // Puri string process ho gayi
        if(i == s.size()) {
            ans.push_back(temp);
            return;
        }

        for(int j = i; j < s.size(); j++) {

            if(palindromic(s, i, j)) {

                // substring add
                temp.push_back(s.substr(i, j - i + 1));

                // next part
                solve(s, ans, temp, j + 1);

                // backtracking
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> temp;

        solve(s, ans, temp, 0);

        return ans;
    }
};