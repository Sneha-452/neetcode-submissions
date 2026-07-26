class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int , int> mp ; 
        int i = 0 ; 
        int maxifreq = 0 ; 
         int ans = 0 ; 
          for(int j = 0 ; j < s.size() ; j++){
            mp[s[j]]++;
            maxifreq = max(maxifreq , mp[s[j]]);

            while((j-i+1) - maxifreq > k){
                mp[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
          }
          return ans;
    }
};
