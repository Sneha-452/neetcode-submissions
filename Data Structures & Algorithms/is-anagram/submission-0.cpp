class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>mp ;
        bool ok = true ;
        if(s.size() != t.size())
    return false;
        for(int i = 0 ; i < s.size() ; i++){
            mp[s[i]]++;
        }
        for(int j = 0 ; j < t.size() ; j++){
            if(mp.find(t[j]) != mp.end()){
                mp[t[j]]--;
            }
        }
            for(auto &i : mp){
                if(i.second != 0){
                    ok = false ;
                }
            
        
      
            }
            return ok ;
    }
};
