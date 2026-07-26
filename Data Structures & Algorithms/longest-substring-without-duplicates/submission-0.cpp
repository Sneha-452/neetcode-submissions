class Solution {
public:
    int lengthOfLongestSubstring(string s) {
          unordered_map<char, int> mp;

    int i = 0, j = 0;
    int maxi = 0;

    while (j < s.size()) {

        if (mp.find(s[j]) == mp.end()) {
            mp[s[j]]++;
            maxi = max(maxi, j - i + 1);
            j++;
        }
        else {
            mp.erase(s[i]);
            i++;
        }
    }

    return maxi;
    }
};
