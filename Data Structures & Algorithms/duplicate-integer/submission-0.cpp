class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp ; 
        bool ok = false ; 
        for(int i = 0 ; i < nums.size() ; i++){
            if(mp.find(nums[i]) != mp.end()){
                ok = true ;
            }
            mp[nums[i]]++;
        }
        return ok ;
    }
};