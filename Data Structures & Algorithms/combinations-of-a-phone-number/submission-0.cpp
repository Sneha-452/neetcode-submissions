class Solution {
public:

    void solve(string& digits, vector<string>& ans,
               string& temp, int i, vector<string>& mp) {

        // saare digits process ho gaye
        if(i == digits.size()) {
            ans.push_back(temp);
            return;
        }

        // current digit
        string letters = mp[digits[i] - '0'];

        for(char ch : letters) {

            // choose
            temp.push_back(ch);

            // next digit
            solve(digits, ans, temp, i + 1, mp);

            // backtrack
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.empty()) {
            return {};
        }

        vector<string> mp(10);

        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        vector<string> ans;
        string temp;

        solve(digits, ans, temp, 0, mp);

        return ans;
    }
};