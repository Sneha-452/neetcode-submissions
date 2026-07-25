class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int , int> mp ;
        vector<int>ans ; 
        for(int i = 0 ; i < nums.size() ; i++){
            int subs = target - nums[i] ; 
            if(mp.find(subs) != mp.end()){
                ans.push_back(mp[subs]+1);
                ans.push_back(i+1);
            }
            mp[nums[i]] = i ;
        }
        return ans ;
    }
};
