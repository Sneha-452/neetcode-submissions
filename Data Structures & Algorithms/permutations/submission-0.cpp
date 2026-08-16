class Solution {
public:

    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& nums, vector<bool>& used) {

        // permutation complete
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // har number ko try karo
        for (int j = 0; j < nums.size(); j++) {

            // agar already use ho chuka hai
            if (used[j] == true)
                continue;

            // choose
            temp.push_back(nums[j]);
            used[j] = true;

            // next position ke liye
            solve(nums, used);

            // backtrack
            temp.pop_back();
            used[j] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<bool> used(nums.size(), false);

        solve(nums, used);

        return ans;
    }
};
