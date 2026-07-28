class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        stack<int>st ; 
        //rightsmaller 
        int n = ht.size();
        vector<int>rightsmaller(n); 
        for(int i = ht.size()-1 ; i >= 0 ; i--){
                   while(!st.empty() && ht[st.top()] >= ht[i]){
                    st.pop() ;
                   }
                   rightsmaller[i] = st.empty() ? n : st.top() ;
                   st.push(i);
        }
         //leftsmaller 
         stack<int>stck;
         vector<int>leftsmaller(n) ; 
        for(int i = 0 ; i < ht.size() ; i++){
            while(!stck.empty() && ht[stck.top()] >= ht[i]){
                stck.pop();
            }
            leftsmaller[i] = stck.empty() ? -1 : stck.top() ; 
            stck.push(i);
        }

        int maxiarea = INT_MIN ; 
        for(int i = 0 ; i < ht.size() ; i++){
             int width = rightsmaller[i] - leftsmaller[i] - 1;
            int height = ht[i] * width;
            maxiarea = max(maxiarea , height) ;

        }
        return maxiarea ;
    }
};
