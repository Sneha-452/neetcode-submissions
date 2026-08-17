class Solution {
public:
 vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string temp;

    solve(0, 0, n, temp, ans);

    return ans;
}

void solve(int open, int close, int n, string& temp, vector<string>& ans) {

    // ek complete valid string ban gayi
    if (open == n && close == n) {
        ans.push_back(temp);
        return;
    }

    // opening bracket laga sakte hain
    if (open < n) {
        temp.push_back('(');

        solve(open + 1, close, n, temp, ans);

        temp.pop_back();   // backtrack
    }

    // closing bracket tabhi laga sakte hain
    if (close < open) {
        temp.push_back(')');

        solve(open, close + 1, n, temp, ans);

        temp.pop_back();   // backtrack
    }
}
};
