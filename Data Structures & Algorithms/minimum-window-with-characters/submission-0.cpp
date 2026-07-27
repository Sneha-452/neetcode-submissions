class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size())
        return "";
        unordered_map<char,int>mp ; 
        int start = 0 ;
        for(auto ch : t)
            mp[ch]++;
        int count = t.size() ; 
        int i = 0 ; 
         int j = 0 ; 
         int minlength = INT_MAX ;
        while(j < s.size()){
            //expanding
          
            if(mp[s[j]] >0)
            count--;
           
           mp[s[j]]--;

           while(count == 0 ){
            // start shrinking

             if(j-i + 1 < minlength){
                minlength = j-i+1;
                start = i ;
             }
             mp[s[i]]++;
             if(mp[s[i]] > 0)
                count++;
             i++;

           }
           
           j++;
           
        }
         return (minlength == INT_MAX) ? "" : s.substr(start, minlength);
    }
};
